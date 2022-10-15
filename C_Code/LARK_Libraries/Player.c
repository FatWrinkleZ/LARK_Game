#include "Player.h"
#define LEFT 'a'
#define RIGHT 'd'
#define FORWARD 'w'
#define BACK 's'

float movementSpeed = 1.0f;
float rotateSpeed = 3.0f;
bool last_line_mode = false;

void LS(){
    DIR *d;

    struct dirent *dir;

    d = opendir("LEVELS");

    char buf[64];
    buf[0] = '\0';
    int c = 0;
    if (d)

    {

        while ((dir = readdir(d)) != NULL)
        {
            strcat(buf, dir->d_name);
            strcat(buf, "\t");
            c++;
            if(c %4 == 0)strcat(buf, "\n");
        }

        closedir(d);

    }
    sprintf(terminalOutput, "%s", buf);

}

void ProcessCommand(char command[32]){
    char cmd[32];
    cmd[0] = '\0';
    sscanf(command, "%s ", cmd);
    if(strcmp(cmd, "ls")==0){
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
        char buf[64];
        buf[0] = '\0';
        for(int i = 0; i < numEntities; i++){
            cnt++;
            if(cnt %4==0)printf("\r\n");
            strcat(buf, ENTITIES[i].name);
            strcat(buf, "\t");
        }
        sprintf(terminalOutput, "%s", buf);
    }else if(strcmp(cmd, "cat")==0){

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
    if(SCREEN[WIDTH/2+(int)direction.x][HEIGHT/2]==' '){
        PLAYER->position.x += direction.x;
    }
    if(SCREEN[WIDTH/2][HEIGHT/2+(int)direction.y]==' '){
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