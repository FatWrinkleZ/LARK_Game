#include "Engine.h"

FILE* myLog;

bool* PLAYING = 0;
int UNIT_SIZE = 4;
int WIDTH = 0, HEIGHT = 0;
int mapX=0, mapY=0;
unsigned char** SCREEN;
char KEYSTROKE = 1;
int FOV = 60;
char BRIGHTNESS_LOOKUP[4] = {'#', '+','-',' '};
short **map;
unsigned char *terminalOutput;
Transform* ENTITIES;
int numEntities = 0;
Transform* PLAYER;
int LEVEL_LOADED;

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
    system("clear");
    bool isBMP = false;
    FILE* file;
    file = fopen(filename, "r");
    if(file == NULL){sprintf(terminalOutput, "LEVEL [%s] NOT FOUND", filename);return -1;}
    sprintf(terminalOutput, "FOUND LEVEL! NOW LOADING...");
    if(map != NULL){
        for(int i = 0; i < mapX; i++){
            free(map[i]);
        }
        free(map);
    }
    fseek(file, 0, SEEK_SET);
    char bmpStr[4];
    bmpStr[0]='\0';
    fread(bmpStr, 2, 1,file);
    if(strcmp(bmpStr, "BM")==0){
        isBMP=true;
        printf("%s\n", bmpStr);
        sscanf(filename, ".LEVELS/lvl%d.", &LEVEL_LOADED);
    }
    fseek(file, 0, SEEK_SET);
    if(isBMP){
        short pixelSize;
        short startLoc;

        fseek(file, 10, SEEK_SET);
        fread(&startLoc, 4, 1, file);
        printf("Found start location [%d]\n", startLoc);

        fseek(file, 18, SEEK_SET);
        fread(&mapX, 4, 1, file);
        printf("Found image width [%d]\n", mapX);

        fseek(file, 22, SEEK_SET);
        fread(&mapY, 4, 1, file);
        printf("Found image height [%d]\n", mapY);

        fseek(file , 28, SEEK_SET);
        fread(&pixelSize, 2, 1, file);
        printf("Found pixel size [%d] (bits)\n", pixelSize);

        fseek(file, startLoc, SEEK_SET);
        map = (short**)malloc(sizeof(short*)*mapX);
        for(int i = 0; i < mapX; i ++){
            map[i] = (short*)malloc(sizeof(short)*mapY);
        }
        for(int i = 0; i < mapY; i++){
            for(int j = 0; j < mapX; j++){
                Pixel p;
                fread(&p, pixelSize/8, 1, file);
                map[j][i] = (p.r + p.g + p.g)/3 <= 128;

            }
            if((pixelSize/3) % 4 != 0){
                fseek(file, 2, SEEK_CUR);
            }
        }

    }else{
        char buf[32];
        buf[0] = '\0';
        fscanf(file, "%[^\n]", buf);
        sscanf(buf, "%d%d lvl%d", &mapX, &mapY, &LEVEL_LOADED);
        //printf("FOUND FILE %d %d\r\n", mapX, mapY);
        
        map = (short**)malloc(sizeof(short*) * mapX);
        for(int i = 0; i < mapX; i++){
            map[i] = (short*)malloc(sizeof(short)*mapY);
        }
        fseek(file, 1, SEEK_CUR);

        char c = 1;
        int x=0,y=0;
        for(int i = mapY; i >= 0; i--){
            for(int j = 0; j <= mapX; j++){
                c = fgetc(file);
                if(c=='#'||c==' '){
                    map[j][i] = (c=='#');
                }
            }
        }
    }
    fclose(file);
    for(int i = mapY-1; i >= 0;i--){
        for(int j = 0; j < mapX; j++){
            putchar(map[j][i] ? '#':' ');
        }
        printf("\r\n");
    }
    printf("FINISHED READING [%s] %s FILE\r\n", filename, ((isBMP==true) ? "BMP" : "TEXT"));
    printf("CONFIRM MAP (any key)\r\n");
    system("/bin/stty raw");
    getchar();
    sprintf(terminalOutput, "LEVEL LOADED");
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
    entity->OnUpdate = NULL;
    entity->level = LEVEL_LOADED;
    sprintf(entity->name, "ENTITY_%d", entity->instanceID);
    entity->isFile = false;
    entity->isJob = true;
    entity->OnUse = NULL;
    entity->useParam = entity;
    entity->OnInteract = NULL;
}

Transform* ADD_ENTITY(){
    Transform* entity;
    numEntities++;
    ENTITIES = (Transform*)realloc(ENTITIES, sizeof(Transform)*numEntities);
    entity = &ENTITIES[numEntities-1];
    entity->instanceID = numEntities-1;
    entity->ALIVE = true;
    entity->level = LEVEL_LOADED;
    INIT(entity);
    for(int i = 0; i < numEntities; i++){
        ENTITIES[i].instanceID = i;
    }
    
    return entity;
}

int Initialize(){
    SCREEN = (char**)malloc(WIDTH * sizeof(char*));
    for(int i = 0; i < WIDTH; i++){
        SCREEN[i] = (char*)malloc(HEIGHT * sizeof(char));
        for(int j = 0; j < HEIGHT; j++){
            SCREEN[i][j] = '-';
        }
    }

    ENTITIES = (Transform*)malloc(sizeof(Transform)*2);
    ENTITIES[0].instanceID = 0;
    sprintf(ENTITIES[0].name, "ROOT");
    ENTITIES[0].OnUpdate = NULL;
    ENTITIES[0].isVisible = false;
    ENTITIES[0].ALIVE = false;
    numEntities=2;
    PLAYER = &ENTITIES[1];
    PLAYER->instanceID = 1;
    INIT(PLAYER);
    PLAYER->tag = 1;
    PLAYER->ALIVE = true;
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
            if(mapx < 0||mapy < 2 || mapx >= mapX || mapy >= mapY){

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
    SCREEN[WIDTH/2][HEIGHT/2]=PLAYER->sprite;
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
            ENTITIES[i].OnUpdate(&ENTITIES[i]);
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
        if(ENTITIES[e].isVisible==false || ENTITIES[e].level != LEVEL_LOADED)continue;
        int mapToScreenPosX = (ENTITIES[e].position.x-PLAYER->position.x) + WIDTH/2;
        int mapToScreenPosY = (ENTITIES[e].position.y-PLAYER->position.y) + HEIGHT/2;
        if(mapToScreenPosX < 0 || mapToScreenPosX >= WIDTH || mapToScreenPosY < 0 || mapToScreenPosY >= HEIGHT || GET_BRIGHTNESS(mapToScreenPosX, mapToScreenPosY)==' '){
            continue;
        }
        SCREEN[mapToScreenPosX][mapToScreenPosY] = ENTITIES[e].sprite;
    }
    for(int i = HEIGHT; i >= 0; i--){
        for(int j = 0; j <WIDTH; j++){
            char c = SCREEN[j][i];
            if(SCREEN[j][i]=='#'){
                c = GET_BRIGHTNESS(j,i);
            }
            if(SCREEN[j][i] != '#'){
                printf("%s", KGRN);
                putchar(c);
                printf("%s",KNRM);
            }else
                putchar(c);
        }
        putchar('\r');
        putchar('\n');
    }
    //refreshing traps
    for(int i = 0; i < numEntities; i++){
        if(ENTITIES[i].tag == 4)
            ENTITIES[i].isVisible = false;
    }
    printf("~$ %s\r\n", terminalOutput);
}

void END(){
    system("/bin/stty cooked");
    fclose(myLog);
    for(int i = 0; i < HEIGHT; i++){
        free(SCREEN[i]);
    }
    free(ENTITIES);
    for(int i = 0; i < mapX; i++){
        free(map[i]);
    }
    free(map);
    free(SCREEN);
    free(terminalOutput);
    exit(0);
}

int Start(int _WIDTH, int _HEIGHT, void (*myStart)(), void (*OnUpdate)()){
    myLog = fopen("lark_log.log", "w");
    if(log == NULL){
        printf("ERROR, could not open file!");
        system("/bin/stty cooked");
        exit(1);
    }
    WIDTH = _WIDTH;
    HEIGHT = _HEIGHT;
    terminalOutput = (char*)malloc(sizeof(char)*1024);
    int levelLoaded = LOAD_LEVEL(".LEVELS/lvl1.level");
    sprintf(terminalOutput, "WASD to move. Press (Esc) to enter command mode. './pickup.sh' when over an item to pick it up. './use.sh' can be used to use the item.\r\nWalk over to the scroll ('@') and pick it up. './use.sh' to read it.");
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
        OnUpdate();
        RenderScreen();
    }
    system("/bin/stty cooked");
    printf("\nFINISHED\n");
    END();
    return 0;
}
