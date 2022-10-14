#include "Player.h"
#define LEFT 'a'
#define RIGHT 'd'
#define FORWARD 'w'
#define BACK 's'

float movementSpeed = 5.0f;
float rotateSpeed = 3.0f;
bool last_line_mode = false;


void ProcessCommand(char command[32]){
    char* cmd;
    sscanf("%s ", cmd);
    
}

void OnPlayerUpdate(){
    char keystroke = getchar();
    switch(keystroke)
    {
    case LEFT:
        PLAYER->rotation += DR * rotateSpeed;
        break;
    case RIGHT:
        PLAYER->rotation -= DR * rotateSpeed;
        break;
    case FORWARD:
        PLAYER->position.y -= cosf(PLAYER->rotation) * movementSpeed / UNIT_SIZE;
        PLAYER->position.x += sinf(PLAYER->rotation) * movementSpeed / UNIT_SIZE;
        break;
    case BACK:
        PLAYER->position.y += cosf(PLAYER->rotation) * movementSpeed / UNIT_SIZE;
        PLAYER->position.x -= sinf(PLAYER->rotation) * movementSpeed / UNIT_SIZE;
        break;
    case ':':
        last_line_mode = true;
    break;
    case '0':
        SetPlaying(0);
        break;
    default:
        break;
    }
    if(last_line_mode){
        system("/bin/stty cooked");
        char command[32];
        scanf("%[^\n]", command);
        ProcessCommand(command);
        system("/bin/stty raw");
    }
    PLAYER->rotation = FixAng(PLAYER->rotation);
}