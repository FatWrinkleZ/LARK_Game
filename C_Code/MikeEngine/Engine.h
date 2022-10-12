#ifndef ENGINE_H_
#define ENGINE_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159f
#define P2 PI/2
#define P3 3*PI/2
#define DR 0.0174533
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

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