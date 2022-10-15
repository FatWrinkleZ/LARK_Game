#include "Player.h"
#define LEFT 'a'
#define RIGHT 'd'
#define FORWARD 'w'
#define BACK 's'

float movementSpeed = 1.0f;
float rotateSpeed = 3.0f;
bool last_line_mode = false;


void ProcessCommand(char command[32]){
    char cmd[32];
    sscanf(command, "%s ", cmd);
    if(strcmp(cmd, "ls")==0){
        
    }else if(strcmp(cmd, "man") == 0){

    }else if(strcmp(cmd, "kill")==0){
        
    }else if(strcmp(cmd, "jobs")==0){

    }else if(strcmp(cmd, "cat")==0){

    }else{
        printf("%s: command not found\nPress Enter to exit command mode", cmd);
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