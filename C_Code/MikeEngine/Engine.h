#ifndef Engine_H
#define Engine_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int PLAYING;

int WIDTH, HEIGHT;

typedef struct {
    float x, y;
}Vector2;

typedef struct{
    Vector2 position;
    void (*OnUpdate)();
    char name[128];
    int tag;
    int instanceID;
}Transform;

Transform* ENTITIES;
int numEntities;
Transform* PLAYER;

void INIT(Transform* entity);

void ADD_ENTITY(Transform* entity);

int Initialize();

int Update();

int Start(int _WIDTH, int _HEIGHT);

#endif
