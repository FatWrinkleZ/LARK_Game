#ifndef ENGINE_H_
#define ENGINE_H_
/*#ifdef __linux
#include <unistd.h>
#endif*/

#define PI 3.14159f
#define P2 PI/2
#define P3 3*PI/2
#define DR 0.0174533

extern int PLAYING;
extern int UNIT_SIZE;
extern int WIDTH, HEIGHT;
extern int mapX, mapY;
extern int map[];

extern char** SCREEN;

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

void INIT(Transform* entity);

void ADD_ENTITY(Transform* entity);

int Initialize();

float Distance(float ax, float ay, float bx, float by, float ang);

void CastRay();

int Update();

void RenderScreen();

int Start(int _WIDTH, int _HEIGHT);
#endif