#include "MikeEngine/Engine.h"
#include "LARK_Libraries/Player.h"

enum TAGS{
    DEFAULT,
    PLAYER_TAG,
    ITEM,
    WALL
};

int playing = 1;

void myUpdate(){

}

void myStart(){
    PLAYER->position.x = 4;
    PLAYER->position.y = 4;
    PLAYER->OnUpdate = (&OnPlayerUpdate);
    PLAYER->rotation = DR*45;
}

int main(){
    PLAYING = &playing;
    //printf("Hello world\n");
    system("/bin/stty raw");
    Start(60, 30, &myStart, &myUpdate);
    system("/bin/stty cooked");
    return 0;
}