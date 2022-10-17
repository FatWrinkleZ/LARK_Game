#include "Player.h"
#define LEFT 'a'
#define RIGHT 'd'
#define FORWARD 'w'
#define BACK 's'

float movementSpeed = 1.0f;
float rotateSpeed = 3.0f;
bool last_line_mode = false;

Transform *item;

void dotSlashCmD(char command[64]){
    char progrm[32];
    terminalOutput[0] = '\0';
    if(sscanf(command, "./%s", progrm)>0){
        if(strcmp(progrm, "pickup.sh")==0){
            for(int i = 0; i < numEntities; i ++){
                if((int)PLAYER->position.x==(int)ENTITIES[i].position.x && (int)PLAYER->position.y == (int)ENTITIES[i].position.y){
                    if(item != NULL){
                        item->position.x = PLAYER->position.x;
                        item->position.y = PLAYER->position.y;
                        item->isVisible = true;
                        item->level = LEVEL_LOADED;
                        strcat(terminalOutput, "\r\nDROPPED ");
                        strcat(terminalOutput, item->name);
                    }
                    ENTITIES[i].isJob = false;
                    ENTITIES[i].isVisible = false;
                    item = &ENTITIES[i];
                    strcat(terminalOutput, "\r\nPICKED UP ");
                    strcat(terminalOutput, ENTITIES[i].name);
                    fprintf(myLog, "%s\n", terminalOutput);
                    break;
                }
            }
        }else if(strcmp(progrm, "drop.sh")==0){
            if(item != NULL){
                item->position.x = PLAYER->position.x;
                item->position.y = PLAYER->position.y;
                item->isVisible = true;
                item->level = LEVEL_LOADED;
                sprintf(terminalOutput, "\r\nDROPPED [%s]", item->name);
                item = NULL;
            }else{
                sprintf(terminalOutput, "\r\nCANNOT DROP : NO ITEM IN INVENTORY");
            }
        }else if(strcmp(progrm, "unlock.sh")==0){
            if(item!=NULL){
                for(int i = 0; i < numEntities; i++){
                    if(ENTITIES[i].tag == 3 && ENTITIES[i].level == LEVEL_LOADED && ENTITIES[i].level == item->name[strlen(item->name)-5]-48){
                        float distX = absolute(PLAYER->position.x - ENTITIES[i].position.x);
                        float distY = absolute(PLAYER->position.y - ENTITIES[i].position.y);
                        if(distX <= 1 && distY <= 1){
                            ENTITIES[i].isVisible = false;
                            ENTITIES[i].ALIVE = false;
                            ENTITIES[i].isJob = false;
                            ENTITIES[i].isFile = false;
                            char bff[32];
                            sprintf(bff, "\r\nUNLOCKED DOOR WITH JOB ID [%d]", ENTITIES[i].instanceID);
                            strcat(terminalOutput, bff);
                        }
                    }
                }
            }
        }else{
            sprintf(terminalOutput, "\r\ncannot find %s: no file or directory", progrm);
        }
    }else{
        sprintf(terminalOutput, "Error, need to feed a program (i.e: pickup.sh, unlock.sh, drop.sh");
    }
}

void LS(){
    DIR *d;

    struct dirent *dir;

    d = opendir("LEVELS");

    char buf[512];
    buf[0] = '\0';
    int c = 0;
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            strcat(buf, dir->d_name);
            strcat(buf, "\t");
            c++;
            if(c %4 == 0)strcat(buf, "\r\n");
        }
        closedir(d);
    }
    for(int i = 1;  i< numEntities; i ++){
        if(ENTITIES[i].isFile){
            strcat(buf, ENTITIES[i].name);
            strcat(buf, "\t");
            c++;
            if(c %4 == 0)strcat(buf, "\n");
        }
    }
    sprintf(terminalOutput, "%s", buf);
    strcat(terminalOutput, "\r\npickup.sh\tdrop.sh\t\tunlock.sh");

}

void ProcessCommand(char command[32]){
    char cmd[32];
    cmd[0] = '\0';
    sscanf(command, "%s ", cmd);
    if(command[0]=='.' && command[1]=='/'){
        dotSlashCmD(command);
    }else if(strcmp(cmd, "ls")==0){
        LS();
    }else if(strcmp(cmd, "man") == 0){
        char buf[32];
        buf[0] = '\0';
        if(sscanf(command, "man %s", buf)<=0){
            sprintf(terminalOutput, "%s", man);
        }else{
            if(strcmp(buf, "ls")==0){
                sprintf(terminalOutput, "%s", man_ls);
            }else if(strcmp(buf, "cat")==0){
                sprintf(terminalOutput, "%s", man_cat);
            }else if(strcmp(buf, "echo")==0){
                sprintf(terminalOutput, "%s", man_echo);
            }else if(strcmp(buf, "jobs")==0){
                sprintf(terminalOutput, "%s", man_jobs);
            }else if(strcmp(buf, "kill")==0){
                sprintf(terminalOutput, "%s", man_kill);
            }else if(strcmp(buf, "cd")==0){
                sprintf(terminalOutput, "%s", man_cd);
            }else{
                sprintf(terminalOutput, "Error : unregonized man [%s]", buf);
            }
        }
    }else if(strcmp(cmd, "kill")==0){
        
    }else if(strcmp(cmd, "jobs")==0){
        short cnt = 0;
        sprintf(terminalOutput, "\r\n");
        for(int i = 0; i < numEntities; i++){
            if(ENTITIES[i].isJob){
                cnt++;
                if(cnt %4==0)printf("\r\n");
                char jid[12];
                sprintf(jid, "[%d]\t", i);
                strcat(terminalOutput, jid);
                strcat(terminalOutput, ENTITIES[i].name);
                strcat(terminalOutput, "\r\n");
            }
        }
        //sprintf(terminalOutput, "%s", buf);
    }else if(strcmp(cmd, "cat")==0){
        char buf[32];
        if(sscanf(command, "cat %s", buf)>0){
            bool found = false;
            for(int i = 1; i < numEntities; i ++){
                if(strcmp(buf, ENTITIES[i].name)==0 && ENTITIES[i].isFile){
                    char info[512];
                    sprintf(info, "\r\nNAME : %s\r\nPOSITION (%d, %d)\r\nIS_VISIBLE = %d\r\nJOB ID = %d\r\nLVL = %d",ENTITIES[i].name, (int)ENTITIES[i].position.x, (int)ENTITIES[i].position.y, ENTITIES[i].isVisible, ENTITIES[i].instanceID, ENTITIES[i].level);
                    sprintf(terminalOutput, "%s", info);
                    found = true;
                    break;
                }
            }
            if(!found){sprintf(terminalOutput, "cannot find %s: no file or directory", buf);}
        }else{
            sprintf(terminalOutput, "Error! usage : cat <file> (keep in mind, .levels cannot be cat'ed)");
        }
    }else if(strcmp(cmd, "echo")==0){
        sscanf(command, "echo %[^\n]", terminalOutput);
    }else if(strcmp(cmd, "cd")==0){
        char buf[64];
        buf[0] = '\0';
        if(sscanf(command, "cd %s", buf)>0){
            char lvl[64];
            lvl[0] = '\0';
            strcat(lvl, "LEVELS/");
            strcat(lvl, buf);
            LOAD_LEVEL(lvl);
            PLAYER->position.x = mapX/2;
            PLAYER->position.y = mapY/2;
        }else{
            sprintf(terminalOutput, "Error! Usage : cd <dir>");
        }
    }else{
        printf("%s: command not found. use 'man' to see avaliable commands\nPress Enter to exit command mode", cmd);
        char c = getchar();
    }
    
}

void OnPlayerUpdate(){
    char keystroke = getchar();
    Vector2 direction = {0,0};
    switch(keystroke)
    {
    case LEFT:
        //PLAYER->rotation += DR * rotateSpeed;
        direction.x --;
        break;
    case RIGHT:
        //PLAYER->rotation -= DR * rotateSpeed;
        direction.x ++;
        break;
    case FORWARD:
        //PLAYER->position.y -= cosf(PLAYER->rotation) * movementSpeed / UNIT_SIZE;
        //PLAYER->position.x += sinf(PLAYER->rotation) * movementSpeed / UNIT_SIZE;
        direction.y++;
        break;
    case BACK:
        //PLAYER->position.y += cosf(PLAYER->rotation) * movementSpeed / UNIT_SIZE;
        //PLAYER->position.x -= sinf(PLAYER->rotation) * movementSpeed / UNIT_SIZE;
        direction.y --;
        break;
    case '$':
        last_line_mode = true;
    break;
    case '0':
        SetPlaying(0);
        break;
    default:
        break;
    }  
    char movTile = SCREEN[WIDTH/2+(int)direction.x][HEIGHT/2 + (int)direction.y];
    if(movTile==' ' || movTile == 'K'){
        PLAYER->position.x += direction.x;
        PLAYER->position.y += direction.y;
    }
    if(last_line_mode){
        system("/bin/stty cooked");
        printf("\r~$ ");
        char command[32];
        fgets(command, 32, stdin);
        ProcessCommand(command);
        last_line_mode = false;
        system("/bin/stty raw");
    }
    PLAYER->rotation = FixAng(PLAYER->rotation);
}