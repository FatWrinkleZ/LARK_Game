#include "Engine.h"

int* PLAYING = 0;
int UNIT_SIZE = 64;
int WIDTH = 0, HEIGHT = 0;
int mapX, mapY;
char** SCREEN;
char KEYSTROKE = 1;

int map[8][8]={
    {1,1,1,1,1,1,1,1},
    {1,0,0,1,0,1,0,1},
    {1,0,0,1,0,1,0,1},
    {1,0,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,1},
    {1,0,0,1,0,1,0,1},
    {1,0,0,1,0,1,0,1},
    {1,1,1,1,1,1,1,1}};

Transform* ENTITIES;
int numEntities = 0;
Transform* PLAYER;

float FixAng(float ang){
    if(ang>2*PI){ ang-=2*PI;} if(ang<0){ ang+=2*PI;} return ang;
}

void INIT(Transform* entity){
    entity->position.x = 0;
    entity->position.y = 0;
    entity->tag = 0;
    entity->rotation = 0.0f;
}

void INIT_POS(Transform* entity, Vector2 position){
    entity->position = position;
    entity->tag = 0;
    entity->rotation = 0.0f;
}

void ADD_ENTITY(Transform* entity){
    numEntities++;
    ENTITIES = (Transform*)realloc(ENTITIES, sizeof(Transform)*numEntities);
    entity = &ENTITIES[numEntities-1];
    entity->instanceID = numEntities-1;
}

int Initialize(){
    SCREEN = (char**)malloc(WIDTH * sizeof(char*));
    for(int i = 0; i < WIDTH; i++){
        SCREEN[i] = (char*)malloc(HEIGHT * sizeof(char));
        for(int j = 0; j < HEIGHT; j++){
            SCREEN[i][j] = '-';
        }
    }

    ENTITIES = (Transform*)malloc(sizeof(Transform));
    numEntities++;
    PLAYER = &ENTITIES[0];
    PLAYER->instanceID = 0;
    INIT(PLAYER);
    PLAYER->tag = 1;
    return ENTITIES==NULL;
}

float Distance(float ax, float ay, float bx, float by, float ang){
    return cosf(ang)*(bx-ax)-sinf(ang)*(by-ay);;
}

void SetPlaying(int var){*PLAYING = var;}

void CastRay(){
    float px = PLAYER->position.x, py = PLAYER->position.y;             
}

int Update(){
    KEYSTROKE = 0;
    for(int i = 0; i < numEntities; i++){
        if(ENTITIES[i].OnUpdate!=NULL){
            ENTITIES[i].OnUpdate();
        }
    }
    return 0;
}

void RenderScreen(){
    system("clear");
    CastRay();
    for(int i = 0; i < HEIGHT; i ++){
        for(int j = 0; j < WIDTH; j++){
            putchar(SCREEN[j][i]);
        }
        //printf("%s\r\n", SCREEN[i]);
        putchar('\r');
        putchar('\n');
    }
    printf("\r\nNEW FRAME\r\n");
    printf("PLAYER (%f, %f) => %f rad\r\n", PLAYER->position.x, PLAYER->position.y, PLAYER->rotation);
}

void END(){
    for(int i = 0; i < HEIGHT; i++){
        free(SCREEN[i]);
    }
    free(ENTITIES);
    free(SCREEN);
}

int Start(int _WIDTH, int _HEIGHT, void (*myStart)(), void (*OnUpdate)()){
    WIDTH = _WIDTH;
    HEIGHT = _HEIGHT;
    //PLAYING = 1;
    Initialize();
    myStart();
    while(*PLAYING != 0){
        RenderScreen();
        //PLAYING = getchar()!='0';
        Update();
        OnUpdate();
        //printf("\r\nEND OF FRAME\r\n");
    }
    system("/bin/stty cooked");
    printf("\nFINISHED\n");
    END();
    return 0;
}