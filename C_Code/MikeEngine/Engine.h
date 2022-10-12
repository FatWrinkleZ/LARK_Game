#ifndef ENGINE_H_
#define ENGINE_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159f
#define P2 PI/2
#define P3 3*PI/2
#define DR 0.0174533

extern int* PLAYING;
extern int UNIT_SIZE;
extern int WIDTH, HEIGHT;
extern int mapX, mapY;
extern int map[24][24];

extern char** SCREEN;

extern char KEYSTROKE;

typedef struct {
    float x, y;
}Vector2;

typedef struct{
    Vector2 position;
    void (*OnUpdate)();
    char name[128];
    int tag;
    int instanceID;
    float rotation;
}Transform;

extern Transform* ENTITIES;
extern int numEntities;
extern Transform* PLAYER;

float FixAng(float ang);

void INIT(Transform* entity);

void ADD_ENTITY(Transform* entity);

int Initialize();

float Distance(float ax, float ay, float bx, float by, float ang);

void SetPlaying(int var);

float absolute(float x);

void CastRay();

int Update();

void RenderScreen();

void END();

int Start(int _WIDTH, int _HEIGHT, void (*myStart)(), void (*OnUpdate)());
#endif