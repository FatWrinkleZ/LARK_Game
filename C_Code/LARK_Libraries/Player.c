#include "Player.h"
#define LEFT 'a'
#define RIGHT 'd'
#define FORWARD 'w'
#define BACK 's'

float movementSpeed = 5.0f;
float rotateSpeed = 3.0f;

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
    case '0':
        SetPlaying(0);
        break;
    default:
        break;
    }
    PLAYER->rotation = FixAng(PLAYER->rotation);


}