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

void SetActive(Transform* t, bool active){
    t->ALIVE = active;
}

void UseLantern(void){
    for(int i = 0; i < numEntities; i++){
        Transform* e = &ENTITIES[i];
        if(e->level != LEVEL_LOADED || strstr(e->name, ".trap")){
            int mapToScreenPosX = (e->position.x-PLAYER->position.x) + WIDTH/2;
            int mapToScreenPosY = (e->position.y-PLAYER->position.y) + HEIGHT/2;
            if(GET_BRIGHTNESS(mapToScreenPosX, mapToScreenPosY)!=' '){
                SCREEN[mapToScreenPosX][mapToScreenPosY]=e->sprite;
            }
        }
    }
}

void UseKey(Transform *key){
    for(int i = 0; i < numEntities; i++){
        if(ENTITIES[i].tag == 3 && ENTITIES[i].level == LEVEL_LOADED){
            float distX = absolute(PLAYER->position.x - ENTITIES[i].position.x);
            float distY = absolute(PLAYER->position.y - ENTITIES[i].position.y);
            if(distX <= 1 && distY <= 1 && ENTITIES[i].name[0] == key->name[0]){
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