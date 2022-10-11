#include "Engine.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int PLAYING = 0;
int UNIT_SIZE = 10;
int WIDTH = 0, HEIGHT = 0;
int mapX, mapY;
char** SCREEN;
int map[] = {
    1,1,1,1,1,1,1,1,
    1,0,0,1,0,1,0,1,
    1,0,0,1,0,1,0,1,
    1,0,0,1,0,1,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,1,0,1,0,1,
    1,0,0,1,0,1,0,1,
    1,1,1,1,1,1,1,1,
};

Transform* ENTITIES;
int numEntities = 0;
Transform* PLAYER;

void INIT(Transform* entity){
    entity->position.x = 0;
    entity->position.y = 0;
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
            SCREEN[i][j] = ' ';
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
    return (sqrtf((bx-ax)*(bx-ax) + (by-ay)*(by-ay)));
}

void CastRay(){
    int r, mx, my, mp, dof; float rx, ry, ra, xo, yo, distT;
    ra = PLAYER->rotation - DR*30;
    if(ra < 0){ra+=2*PI;}
    if(ra>2*PI){ra-=2*PI;}
    for(r = 0; r < 60; r++){
        //HORIZONTAL CHECK
        dof = 0;
        float disH=1000000,hx=PLAYER->position.x, hy=PLAYER->position.y;
        float aTan = -1/tanf(ra);
        if(ra > PI){
            ry = (((int)PLAYER->position.y>>6)<<6)-0.0001f; 
            rx = (PLAYER->position.y-ry)*aTan;
            yo=-UNIT_SIZE;
            xo = -yo*aTan;
        }
        if(ra < PI){
            ry = (((int)PLAYER->position.y>>6)<<6)+UNIT_SIZE; 
            rx = (PLAYER->position.y-ry)*aTan;
            yo=UNIT_SIZE;
            xo = -yo*aTan;
        }
        if(ra==0 || ra == PI){
            rx=PLAYER->position.x;
            ry = PLAYER->position.y;
            dof = 8;
        }
        while(dof < 8){
            mx=(int)(rx)>>6;
            my=(int)(r)>>6;
            mp = my*mapX+mx;
            if(mp > 0 && mp<mapX*mapY && map[mp]==1){hx = rx; hy = ry; disH = Distance(PLAYER->position.x, PLAYER->position.y, hx, hy, ra);dof = 8;}
            else{rx + xo; ry + yo; dof+=1;}
        }
        //VERTICAL LINES
        dof = 0;
        float disV=1000000,vx=PLAYER->position.x, vy=PLAYER->position.y;
        float nTan = -tanf(ra);
        if(ra > P2 && ra < P3){
            rx = (((int)PLAYER->position.x>>6)<<6)-0.0001f; 
            ry = (PLAYER->position.x-rx)*nTan;
            xo=-UNIT_SIZE;
            yo = -xo*nTan;
        }
        if(ra < P2 || ra > P3){
            rx = (((int)PLAYER->position.x>>6)<<6)+UNIT_SIZE; 
            ry = (PLAYER->position.x-rx)*nTan;
            xo=UNIT_SIZE;
            yo = -xo*nTan;
        }
        if(ra==0 || ra == PI){
            ry=PLAYER->position.y;
            rx = PLAYER->position.x;
            dof = 8;
        }
        while(dof < 8){
            mx=(int)(rx)>>6;
            my=(int)(r)>>6;
            mp = my*mapX+mx;
            if(mp>0 && mp<mapX*mapY && map[mp]==1){vx = rx; vy = ry; disV = Distance(PLAYER->position.x, PLAYER->position.y, hx, hy, ra); dof = 8;}
            else{rx + xo; ry + yo; dof+=1;}
        }
        if(disV<disH){rx=vx; ry=vy; distT = disV;}
        if(disV>disH){rx=hx; ry=hy; distT = disH;}

        float lineH = ((mapX * mapY)*HEIGHT)/distT;
        lineH = lineH > 320 ? 320 : lineH;

        ra+=DR;
        if(ra < 0){ra+=2*PI;}
        if(ra>2*PI){ra-=2*PI;}
    }
}

int Update(){
    for(int i = 0; i < numEntities; i++){
        if(ENTITIES[i].OnUpdate!=NULL){
            ENTITIES[i].OnUpdate();
        }
    }
    return 0;
}

void RenderScreen(){
    system("clear");

    for(int i = 0; i < WIDTH; i ++){
        for(int j = 0; j < HEIGHT; j++){
            putchar(SCREEN[i][j]);
        }
        putchar('\n');
    }
}

int Start(int _WIDTH, int _HEIGHT){
    WIDTH = _WIDTH;
    HEIGHT = _HEIGHT;
    PLAYING = 1;
    Initialize();
    while(PLAYING){
        Update();
        RenderScreen();
    }
    free(ENTITIES);
    for(int i = 0; i < WIDTH; i++){
        free(SCREEN[i]);
    }
    free(SCREEN);
    return 0;
}