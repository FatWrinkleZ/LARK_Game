#include "entity_functions.h"

void TriggerUpdate(Transform* this){
    if(this->ALIVE && (int)this->position.x == (int)PLAYER->position.x && (int)this->position.y == (int)PLAYER->position.y){
        WriteToTerminalOutput(this->name);
        this->ALIVE = false;
    }
}

void WriteToTerminalOutput(char* str){
    sprintf(terminalOutput, "%s", str);
}

void AddToTerminalOutput(char* str){
    char buf[256];
    sprintf(buf, "\r\n %s %s %s", KWHT, str, KNRM);
    strcat(terminalOutput, buf);
}

void SetActive(Transform* t, bool active){
    t->ALIVE = active;
}

void UseLantern(void){
    for(int i = 0; i < numEntities; i++){
        Transform* e = &ENTITIES[i];
        if(e->level == LEVEL_LOADED && strstr(e->name, ".trap")){
            int mapToScreenPosX = (e->position.x-PLAYER->position.x) + WIDTH/2;
            int mapToScreenPosY = (e->position.y-PLAYER->position.y) + HEIGHT/2;
            if(GET_BRIGHTNESS(mapToScreenPosX, mapToScreenPosY)!=' '){
                SCREEN[mapToScreenPosX][mapToScreenPosY]=e->sprite;
                e->isVisible = true;
                char buf[64];
                sprintf(buf, "\r\nFOUND [%s]", e->name);
                AddToTerminalOutput(buf);
            }
        }
    }
}

void UseKey(Transform *key){
    fprintf(myLog, "CALLED UseKey(%s) => UnlockID : %c => LEVEL_LOADED : %d\n",key->name, key->name[0], LEVEL_LOADED);
    for(int i = 0; i < numEntities; i++){
        fprintf(myLog, "\tFound Entitity [%s] in Level [%d] with TAG [%d]\n", ENTITIES[i].name, ENTITIES[i].level, ENTITIES[i].tag);
        if(ENTITIES[i].tag == 3 && ENTITIES[i].level == LEVEL_LOADED){
            fprintf(myLog, "\t\tFound Door [%s] With UnlockID : %c\n", ENTITIES[i].name, ENTITIES[i].name[0]);
            float distX = absolute(PLAYER->position.x - ENTITIES[i].position.x);
            float distY = absolute(PLAYER->position.y - ENTITIES[i].position.y);
            if(distX <= 1 && distY <= 1 && ENTITIES[i].name[0] == ENTITIES[key->instanceID].name[0]){
                ENTITIES[i].isVisible = false;
                ENTITIES[i].ALIVE = false;
                ENTITIES[i].isJob = false;
                ENTITIES[i].isFile = false;
                char bff[64];
                sprintf(bff, "\r\nUNLOCKED DOOR [%s] WITH [%s]",ENTITIES[i].name,  key->name);
                strcat(terminalOutput, bff);
            }else if (distX <= 1 && distY <= 1){
                char buffer[64];
                sprintf(buffer, "Can't use %s on %s\r\n", key->name,ENTITIES[i].name );
                strcat(terminalOutput, buffer);
            }
        }
    }
}

void TriggerTrap(Transform *t){
    if(t->level == LEVEL_LOADED && (int)t->position.x == (int)PLAYER->position.x && (int)t->position.y == (int)PLAYER->position.y){
        int trapDMG = -15;
        PLAYER->OnUse(&trapDMG);
        sprintf(terminalOutput, "\r\nPLAYER STEPPED ON [%s], [%d] damage was done\r\nUse './stats.sh' to see current health", t->name, -15);
    }
    return;
}
void TriggerTrapOnce(Transform *t){
    if(t->ALIVE && t->level == LEVEL_LOADED && (int)t->position.x == (int)PLAYER->position.x && (int)t->position.y == (int)PLAYER->position.y){
        int trapDMG = -15;
        PLAYER->OnUse(&trapDMG);
        sprintf(terminalOutput, "\r\nPLAYER STEPPED ON [%s], [%d] damage was done\r\nUse './stats.sh' to see current health", t->name, -15);
        t->ALIVE = false;
    }
    return;
}

void OpenChest(Transform *t){
    t->ALIVE = false;
    t->isFile = false;
    t->isJob = false;
    t->isVisible = false;
    char buf[128];
    sprintf(buf, "\r\n %s You found a healing potion in [%s]. You drink it and regain 10 health %s \r\n",KGRN, t->name,KNRM);
    strcat(terminalOutput, buf);
    int hp = 10;
    PLAYER->OnUse(&hp);
}