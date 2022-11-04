#include "Player.h"
#define LEFT 'a'
#define RIGHT 'd'
#define FORWARD 'w'
#define BACK 's'

int health = 100;

float movementSpeed = 1.0f;
float rotateSpeed = 3.0f;
bool last_line_mode = false;
char suPass[64]="TuxTorvalds1991";
bool su = false;

Transform *item;

void dotSlashCmD(char command[64]){
    char progrm[32];
    terminalOutput[0] = '\0';
    if(sscanf(command, "./%s", progrm)>0){
        if(strcmp(progrm, "pickup.sh")==0){
            for(int i = 2; i < numEntities; i ++){
                if(ENTITIES[i].tag = 2 && ENTITIES[i].isVisible &&(int)PLAYER->position.x==(int)ENTITIES[i].position.x && (int)PLAYER->position.y == (int)ENTITIES[i].position.y){
                    if(item != NULL){
                        item->position.x = PLAYER->position.x;
                        item->position.y = PLAYER->position.y;
                        item->isVisible = true;
                        item->isJob = true;
                        item->isFile = true;
                        item->level = LEVEL_LOADED;
                        strcat(terminalOutput, "\r\nDROPPED ");
                        strcat(terminalOutput, item->name);
                    }
                    item = &ENTITIES[i];
                    item->isFile = false;
                    item->isJob = false;
                    item->isVisible = false;
                    strcat(terminalOutput, "\r\nPICKED UP ");
                    strcat(terminalOutput, ENTITIES[i].name);
                    fprintf(myLog, "%s\n", terminalOutput);
                    printf("\a");
                    break;
                }
            }
        }else if(strcmp(progrm, "drop.sh")==0){
            if(item != NULL){
                item->position.x = PLAYER->position.x;
                item->position.y = PLAYER->position.y;
                item->isVisible = true;
                item->isJob = true;
                item->isFile = true;
                item->level = LEVEL_LOADED;
                sprintf(terminalOutput, "\r\nDROPPED [%s]", item->name);
                item = NULL;
            }else{
                sprintf(terminalOutput, "\r\nCANNOT DROP : NO ITEM IN INVENTORY");
            }
        }else if(strcmp(progrm, "use.sh")==0){
            if(item!=NULL && item->OnUse != NULL){
                item->OnUse(item->useParam);
            }
        }else if(strcmp(progrm, "stats.sh")==0){
            sprintf(terminalOutput, "\r\nHEALTH = %d\r\nCURRENT ITEM = %s\r\nLEVEL_LOADED = %d", health, item==NULL ? "[no_item_in_inventory]" : item->name, LEVEL_LOADED);
        }else if(strcmp(progrm, "inspect.sh")==0){
            for(int i = 0; i < numEntities; i++){
                if(ENTITIES[i].level == LEVEL_LOADED && ENTITIES[i].ALIVE && ENTITIES[i].isVisible){
                    float distX = absolute(PLAYER->position.x - ENTITIES[i].position.x);
                    float distY = absolute(PLAYER->position.y - ENTITIES[i].position.y);
                    if(distX <= 1 && distY <= 1){
                        char buf[128];
                        sprintf(buf, "\r\nYou inspected [%s]. It looks like [%c] and you %s pick it up.", ENTITIES[i].name, ENTITIES[i].sprite, (ENTITIES[i].tag == 2) ? "can" : "can't");
                        strcat(terminalOutput, buf);
                        if(ENTITIES[i].OnInteract != NULL){
                            ENTITIES[i].OnInteract(ENTITIES[i].useParam);
                        }
                    }
                }
            }
        }else{
            sprintf(terminalOutput, "\r\ncannot find %s: no file or directory", progrm);
        }
    }else{
        sprintf(terminalOutput, "Error, need to feed a program (i.e: pickup.sh, use.sh, drop.sh, ect...");
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
            if(strstr(dir->d_name, ".secret")== NULL){
                c++;
                strcat(buf, dir->d_name);
                strcat(buf, "\t");
                if(c %4 == 0)strcat(buf, "\r\n");
            }
        }
        closedir(d);
    }
    for(int i = 1;  i< numEntities; i ++){
        if(ENTITIES[i].isFile){
            strcat(buf, ENTITIES[i].name);
            strcat(buf, "\t");
            c++;
            if(c %4 == 0)strcat(buf, "\r\n");
        }
    }
    sprintf(terminalOutput, "%s", buf);
    strcat(terminalOutput, "\r\npickup.sh\tdrop.sh\t\tuse.sh\t\tstats.sh\r\ninspect.sh");

}

void SU(){
    if(su){
        sprintf(terminalOutput, "Already root user\r\nAborting...");
        return;
    }
    char pass[64];
    printf("\r\nEnter password for ROOT: ");
    scanf("%s", pass);
    if(strcmp(pass, suPass)==0){
        sprintf(terminalOutput, "\r\nSuccess! You are now ROOT user!");
        su = true;
    }else{
        sprintf(terminalOutput, "\r\nIncorrect password for ROOT!\r\nExiting...");
    }
}

void ProcessCommand(char command[32]){
    fprintf(myLog, "PLAYER INPUTTED COMMAND [%s]\n", command);
    char cmd[32];
    cmd[0] = '\0';
    sscanf(command, "%s ", cmd);
    if(command[0]=='.' && command[1]=='/'){
        dotSlashCmD(command);
    }else if(strcmp(cmd, "su")==0){
        SU();
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
            }else if(strcmp(buf, "exit")==0){
                sprintf(terminalOutput, "%s", man_exit);
            }else if(strcmp(buf, "cd")==0){
                sprintf(terminalOutput, "%s", man_cd);
            }else{
                sprintf(terminalOutput, "Error : unregonized man [%s]", buf);
            }
        }
    }else if(strcmp(cmd, "exit")==0){
        if(!su){
            sprintf(terminalOutput, "\r\nPermission Denied");
        }else{
            printf("Congragulations! You beat the game and exited the system!\r\nThanks for playing!");
            END();
        }
    }else if(strcmp(cmd, "jobs")==0){
        short cnt = 0;
        sprintf(terminalOutput, "\r\n");
        for(int i = 0; i < numEntities; i++){
            if(ENTITIES[i].isJob && ENTITIES[i].level == LEVEL_LOADED){
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
                    sprintf(info, "\r\nNAME : %s\r\nPOSITION (%d, %d)\r\nSPRITE = %c\r\nIS_VISIBLE = %d\r\nJOB ID = %d\r\nLVL = %d",ENTITIES[i].name, (int)ENTITIES[i].position.x, (int)ENTITIES[i].position.y, ENTITIES[i].sprite,ENTITIES[i].isVisible,  ENTITIES[i].instanceID, ENTITIES[i].level);
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
        return;
    }
    
}

bool isASolidBlock(char c){
    char BLOCKS[5] = {'#', '+', '-', '%','X'};
    int len = sizeof(BLOCKS)/sizeof(char);
    for(int i = 0; i < len;i++){
        if(c==BLOCKS[i]){
            return true;
        }
    }
    return false;
}

void OnPlayerUpdate(Transform* this){
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
    case 27:
        last_line_mode = true;
    break;
    case 'q':
        SetPlaying(0);
        break;
    default:
        break;
    }  
    char movTile = SCREEN[WIDTH/2+(int)direction.x][HEIGHT/2 + (int)direction.y];
    if(!isASolidBlock(movTile)){
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

void ModifyHealth(int* hp){
    health += *hp;
    if(health<=0){
        printf("\r\n\r\nYOU DIED\r\n\r\n\r\n");
        END();
    }
}
