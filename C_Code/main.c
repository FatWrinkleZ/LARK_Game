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
Transform *entity4;

void LOG_ENTITIES(){
    for(int i = 0; i < numEntities; i++){
        fprintf(myLog, "CREATED ENTITY : [%s] with [%d] Instance ID\n", ENTITIES[i].name, ENTITIES[i].instanceID);
    }
}

void myUpdate(){

}

void myStart(){
    //LOAD_LEVEL("LEVELS/lvl1.level");
    PLAYER->position.x = mapX/2;
    PLAYER->position.y = mapY/2;
    PLAYER->OnUpdate = (&OnPlayerUpdate);
    PLAYER->rotation = PI/2;
    PLAYER->tag = PLAYER_TAG;
    PLAYER->sprite = '$';
    sprintf(PLAYER->name, "PLAYER");

    entity1 = ADD_ENTITY();
    entity1->isFile = true;
    entity1->isJob = true;
    entity1->isVisible = true;
    entity1->sprite = 'K';
    entity1->position.x = 55;
    entity1->position.y = 28;
    entity1->tag = 2;
    entity1->level = 2;
    sprintf(entity1->name, "KEY_LVL1.key");

    entity2 = ADD_ENTITY();
    entity2->isFile = true;
    entity2->isJob = true;
    entity2->isVisible = true;
    entity2->level = 1;
    entity2->position.x = 10;
    entity2->position.y = 10;
    entity2->sprite = 'K';
    entity2->tag = 2;
    sprintf(entity2->name, "KEY_LVL2.key");

    entity3 = ADD_ENTITY();
    entity3->isFile = true;
    entity3->sprite = '%';
    entity3->level = 1;
    entity3->position.x = 10;
    entity3->position.y = 26;
    entity3->isVisible = true;
    entity3->tag = 3;
    sprintf(entity3->name, "DOOR_LVL1");

    entity4 = ADD_ENTITY();
    entity4->isFile = true;
    entity4->sprite = '%';
    entity4->level = 2;
    entity4->position.x = 45;
    entity4->position.y = 17;
    entity4->isVisible = true;
    entity4->tag = 3;
    sprintf(entity4->name, "DOOR_LVL2");
    LOG_ENTITIES();
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