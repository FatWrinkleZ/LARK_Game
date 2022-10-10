#include "Engine.h"

void INIT(Transform* entity){
    entity->position.x = 0;
    entity->position.y = 0;
    entity->tag = 0;
}

void ADD_ENTITY(Transform* entity){
    numEntities++;
    ENTITIES = (Transform*)realloc(ENTITIES, sizeof(Transform)*numEntities);
    entity = &ENTITIES[numEntities-1];
    entity->instanceID = numEntities-1;
}

int Initialize(){
    ENTITIES = (Transform*)malloc(sizeof(Transform));
    numEntities++;
    PLAYER = &ENTITIES[0];
    PLAYER->instanceID = 0;
    INIT(PLAYER);
    PLAYER->tag = 1;
    return ENTITIES==NULL;
}

int Update(){
    for(int i = 0; i < numEntities; i++){
        ENTITIES[i].OnUpdate();
    }
    return 0;
}

int Start(int _WIDTH, int _HEIGHT){
    WIDTH = _WIDTH;
    HEIGHT = _HEIGHT;
    PLAYING = 1;
    Initialize();
    while(PLAYING){

    }

    return 0;
}