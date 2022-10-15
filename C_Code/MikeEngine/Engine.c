#include "Engine.h"

bool* PLAYING = 0;
int UNIT_SIZE = 4;
int WIDTH = 0, HEIGHT = 0;
int mapX=0, mapY=0;
char** SCREEN;
char KEYSTROKE = 1;
int FOV = 60;
char BRIGHTNESS_LOOKUP[4] = {'#', '+','-',' '};
short **map;
/*int map[24][24]={
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};*/

Transform* ENTITIES;
int numEntities = 0;
Transform* PLAYER;

char GET_BRIGHTNESS(int posX, int posY){
    float distX = WIDTH/(float)2 - posX, distY = HEIGHT/(float)2-posY;
    float dist = sqrtf((distX*distX)+(distY*distY));
    if(dist <= 5){
        return BRIGHTNESS_LOOKUP[0];
    }else if(dist <= 7){
        return BRIGHTNESS_LOOKUP[1];
    }else if(dist <= 9){
        return BRIGHTNESS_LOOKUP[2];
    }
    return BRIGHTNESS_LOOKUP[3];
}

int LOAD_LEVEL(const char* filename){
    FILE* file;
    file = fopen(filename, "r");
    if(file == NULL){printf("LEVEL NOT FOUND\n");exit(0);}
    if(map != NULL){
        for(int i = 0; i < mapX; i++){
            free(map[i]);
        }
        free(map);
    }
    fseek(file, 0, SEEK_SET);
    
    char buf[32];
    fscanf(file, "%[^\n]", buf);
    sscanf(buf, "%d%d", &mapX, &mapY);
    printf("FOUND FILE %d %d\r\n", mapX, mapY);
    
    map = (short**)malloc(sizeof(short*) * mapX);
    for(int i = 0; i < mapX; i++){
        map[i] = (short*)malloc(sizeof(short)*mapY);
    }
    fseek(file, 1, SEEK_CUR);

    printf("ALLOCATED TO MAP\r\n");
    char c = 1;
    int x=0,y=0;
    for(int i = mapY; i >= 0; i--){
        for(int j = 0; j <= mapX; j++){
            fprintf(stdout, "\rAT COORD (%d, %d)   \r\n", i, j);
            c = fgetc(file);
            if(c=='#'||c==' '){
                map[j][i] = (c=='#');
                fprintf(stdout, "%c", c);
            }
        }
        printf("\r\n");
    }
    printf("FINISHED READING LEVEL FILE\n");
    for(int i = 0; i < mapX; i++){
        for(int j = 0; j < mapY; j++){
            putchar(map[i][j] ? '#':' ');
        }
        printf("\r\n");
    }
    printf("CONFIRM MAP\r\n");
    getchar();
    fclose(file);
    return 0;
}

float FixAng(float ang){
    if(ang>2*PI){ ang-=2*PI;} if(ang<0){ ang+=2*PI;} return ang;
}

void INIT(Transform* entity){
    entity->position.x = 0;
    entity->position.y = 0;
    entity->tag = 0;
    entity->rotation = 0.0f;
    entity->sprite = ' ';
    entity->isVisible = false;
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
    return cosf(ang)*(bx-ax)-sinf(ang)*(by-ay);
}

void SetPlaying(int var){*PLAYING = var;}

float absolute(float x){
    return x > 0 ? x : x*-1;
}

void Process_Top_Down(){
    float px = PLAYER->position.x, py = PLAYER->position.y;
    float offsetX = WIDTH/2, offsetY = HEIGHT/2;
    int maxCamX = (int)(px + WIDTH/2), maxCamY = (int)(py + (HEIGHT/2));
    int minCamx = (int)(px - WIDTH/2), minCamy = (int)(py - (HEIGHT/2));
    printf("SCREEN TO WORLD COORDS => MAX(%d, %d), MIN(%d, %d)\r\n", maxCamX, maxCamY, minCamx, minCamy);
    printf("PLAYER COORDS (%f, %f)\r\n", PLAYER->position.x, PLAYER->position.y);
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            int mapx=(px-offsetX) + (float)i, mapy=(py-offsetY)+(float)j;
            if(mapx < 0||mapy < 0 || mapx >= mapX || mapy >= mapY){

                SCREEN[i][j] = '#';
                continue;
            }
            if(map[mapx][mapy]!=0){
                SCREEN[i][j] = '#';
                continue;
            }
            SCREEN[i][j] = ' ';
        }
    }
    SCREEN[WIDTH/2][HEIGHT/2]='P';
}

void CastRay(){
    for(int i = 0; i < 24; i ++){
        for(int j = 0; j < 24; j++){
            map[i][j] = map[i][j]!=0 ? 1 : 0;
        }
    }
    float px = PLAYER->position.x, py = PLAYER->position.y;
    float pangle = ((PLAYER->rotation) - (FOV/2.0f)*PI/180)-(PI/2);
    for(int x = 0; x < WIDTH; x++){
        int mapx = (int)px;
        int mapy = (int)py;
        float sideDistX, sideDistY;
        float cameraX = 2 * x / WIDTH-1;
        float rayDirX = cosf(pangle) + 0 * cameraX;
        float rayDirY = sinf(pangle) + 0.66f * cameraX;
        float deltaDistX = (rayDirX == 0) ? 1e30 : absolute(1.0f / rayDirX);
        float deltaDistY = (rayDirY == 0) ? 1e30 : absolute(1.0f / rayDirY);
        int stepX, stepY;
        int hit = 0, side;
        if(rayDirX < 0){
            stepX = -1;
            sideDistX = (px - mapx)*deltaDistX;
        }else{
            stepX = 1;
            sideDistX = (mapx + 1.0f - px)*deltaDistX;
        }
        if(rayDirY < 0){
            stepY = -1;
            sideDistY = (py-mapy)*deltaDistY;
        }else{
            stepY = 1;
            sideDistY = (mapy + 1.0f - py)*deltaDistY;
        }
        char c = ' ';
        while(hit == 0){
            if(sideDistX < sideDistY){
                sideDistX += deltaDistX;
                mapx += stepX;
                side = 0;
                c = '+';
            }else{
                sideDistY += deltaDistY;
                mapy+=stepY;
                side = 1;
                c = '#';
            }
            if(map[mapx][mapy]!=0){
                hit = 1;
                map[mapx][mapy]=2;
            }
        }
        float perpWallDist = (side == 0) ? (sideDistX - deltaDistX) : sideDistY-deltaDistY;

        int lineHeight = (int)(HEIGHT/perpWallDist);
        int drawStart = -lineHeight/2+HEIGHT/2;
        if(drawStart < 0)drawStart = 0;
        int drawEnd = lineHeight /2 + HEIGHT /2;
        if(drawEnd >= HEIGHT)drawEnd = HEIGHT-1;
        for(int h = 0; h < HEIGHT; h++){
            if(h >= drawStart && h <= drawEnd){
                SCREEN[x][h] = c;
            }else{
                SCREEN[x][h] = ' ';
            }
        }
        pangle=FixAng(pangle + PI/180.0f);
    }             
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

void renderMinimap(){
    printf("PLAYER (%f, %f) => %f rad => %f degrees\r\n", PLAYER->position.x, PLAYER->position.y, PLAYER->rotation, PLAYER->rotation * 180/PI);
    for(int i = 23; i >= 0; i--){
        for(int j = 23; j >= 0 ; j--){
            if(i == (int)PLAYER->position.x && j == (int)PLAYER->position.y){
                float rot = PLAYER->rotation * 180/PI;
                if(rot >= 315 || rot <= 45){
                    putchar('>');
                }else if(rot > 45 && rot <= 135){
                    putchar('^');
                }else if(rot > 135 && rot <= 225){
                    putchar('<');
                }else{
                    putchar('v');
                }
            }else{
                if(map[i][j] != 0){
                    printf("%s", map[i][j] == 2 ? KGRN : KNRM);
                    putchar('#');
                    printf("%s", KNRM);
                }else{
                    putchar(' ');
                }
                //putchar(map[i][j] == 0 ? ' ' : '#');
            }
        }
        printf("\r\n");
    }

}

void RenderScreen(){
    system("clear");
    //CastRay();
    Process_Top_Down();
    for(int e = 1; e < numEntities; e++){
        int mapToScreenPosX = (PLAYER->position.x - ENTITIES[e].position.x) + WIDTH/2;
        int mapToScreenPosY = (PLAYER->position.y - ENTITIES[e].position.y) - HEIGHT/2;
        if(mapToScreenPosX < 0 || mapToScreenPosX >= WIDTH || mapToScreenPosY < 0 || mapToScreenPosY >= HEIGHT){
            continue;
        }
        SCREEN[(int)ENTITIES[e].position.x][(int)ENTITIES[e].position.y] = ENTITIES[e].sprite;
    }
    for(int i = HEIGHT; i >= 0; i--){
        for(int j = 0; j <WIDTH; j++){
            char c = SCREEN[j][i];
            if(SCREEN[j][i]=='#'){
                c = GET_BRIGHTNESS(j,i);
            }
                putchar(c);
        }
        putchar('\r');
        putchar('\n');
    }
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
    int levelLoaded = LOAD_LEVEL("LEVELS/lvl1.level");
    if(levelLoaded == -1){
        system("/bin/stty cooked");
        printf("LEVEL NOT FOUND!\n");
        exit(0);
    }
    //PLAYING = 1;
    Initialize();
    myStart();
    RenderScreen();
    while(*PLAYING != 0){
        Update();
        RenderScreen();
        OnUpdate();
    }
    system("/bin/stty cooked");
    printf("\nFINISHED\n");
    END();
    return 0;
}