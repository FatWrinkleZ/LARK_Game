#include "MikeEngine/Engine.h"
#include "LARK_Libraries/Player.h"

enum TAGS{
    DEFAULT,
    PLAYER_TAG,
    KEY,
    DOOR,
};

int playing = 1;

Transform *ROOT;
Transform *entity1;
Transform *entity2;
Transform *entity3;

void myUpdate(){

}

void myStart(){
    //LOAD_LEVEL("LEVELS/lvl1.level");
    PLAYER->position.x = 4;
    PLAYER->position.y = 4;
    PLAYER->OnUpdate = (&OnPlayerUpdate);
    PLAYER->rotation = PI/2;
    PLAYER->tag = PLAYER_TAG;
    PLAYER->sprite = '$';
    sprintf(PLAYER->name, "PLAYER");
    entity1 = ADD_ENTITY();
    entity2 = ADD_ENTITY();
    entity3 = ADD_ENTITY();
}

int main(){
    system("/bin/stty raw");
    //LOAD_LEVEL("LEVELS/lvl1.level");
    //return 0;
    PLAYING = &playing;
    //printf("Hello world\n");
    Start(60, 30, &myStart, &myUpdate);
    system("/bin/stty cooked");
    return 0;
}