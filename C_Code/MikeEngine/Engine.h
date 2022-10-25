#ifndef ENGINE_H_
#define ENGINE_H_
#define bool short
#define true 1
#define false 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

extern FILE* myLog;
extern bool* PLAYING;
extern int UNIT_SIZE;
extern int WIDTH, HEIGHT;
extern int mapX, mapY;
extern short** map;
extern int FOV;
extern char BRIGHTNESS_LOOKUP[4];
extern unsigned char **SCREEN;
extern unsigned char *terminalOutput;

extern char KEYSTROKE;

typedef struct{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}Pixel;

typedef struct {
    float x, y;
}Vector2;

typedef struct{
    Vector2 position;
    void (*OnUpdate)(void*);
    char name[128];
    int tag;
    int instanceID;
    float rotation;
    unsigned char sprite;
    bool isVisible;
    int level;
    bool ALIVE;
    bool isJob;
    bool isFile;
    void (*OnUse)(void *);
    void *useParam;
    void (*OnInteract)(void *);
}Transform;

extern Transform* ENTITIES;
extern int numEntities;
extern Transform* PLAYER;
extern int LEVEL_LOADED;

//returns the character from the lookup table based on a tile's ditance from the player (IN SCREENPOSITION)
char GET_BRIGHTNESS(int posX, int posY);

//loads a level, filename is the path of the level
int LOAD_LEVEL(const char* filename);

//LEGACY FPS CODE [makes bounds of an angle to that of the unit circle (i.e: 0 -> 2PI)]
float FixAng(float ang);

//Function that Initializes an Transform with default values. Think of it like a constructor.
void INIT(Transform* entity);

//Adds the Transform to the "master list" of Transform so thats it's OnUpdate void pointer can be called every Update
Transform* ADD_ENTITY();

//Allocates a base amount of memory to all the pointers, sets up the screen, player, and entities
int Initialize();

//LEGACY FPS CODE [standard distance function based on angle rather than pythagorean theorem]
float Distance(float ax, float ay, float bx, float by, float ang);

//A way to modify the PLAYING bool via function
void SetPlaying(int var);

//Gets the absolute value for floats since math.h does not support it
float absolute(float x);

//Processes the top-down window for the screen
void Process_Top_Down();

//LEGACY FPS CODE [shoots a calculated amount of rays based on the FOV global variable]
void CastRay();

//Calls the update function for every Transform in the master-list (ENTITIES)
int Update();

//LEGACY FPS CODE [used for rendering a minimap under the camera frustrum when the game was first person]
void renderMinimap();

//Outputs the screen to the terminal window
void RenderScreen();

//Frees all memory allocated to the heap
void END();

//The function that does all the setup for you
int Start(int _WIDTH, int _HEIGHT, void (*myStart)(), void (*OnUpdate)());
#endif