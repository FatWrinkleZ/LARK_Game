#include "Player.h"
#define LEFT 'a'
#define RIGHT 'd'
#define FORWARD 'w'
#define BACK 's'

float movementSpeed = 1.0f;
float rotateSpeed = 3.0f;

void OnPlayerUpdate(){
    char keystroke = getchar();
    switch(keystroke)
    {
    case LEFT:
        PLAYER->rotation -= DR * rotateSpeed;
        break;
    case RIGHT:
        PLAYER->rotation += DR * rotateSpeed;
        break;
    case FORWARD:
        PLAYER->position.x += cosf(PLAYER->rotation) * movementSpeed;
        PLAYER->position.y += sinf(PLAYER->rotation) * movementSpeed;
        break;
    case BACK:
        PLAYER->position.x -= cosf(PLAYER->rotation) * movementSpeed;
        PLAYER->position.y -= sinf(PLAYER->rotation) * movementSpeed;
        break;
    case '0':
        SetPlaying(0);
        break;
    default:
        break;
    }

}