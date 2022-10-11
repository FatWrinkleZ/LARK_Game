#include "MikeEngine/Engine.h"

enum TAGS{
    DEFAULT,
    PLAYER_TAG,
    ITEM,
    WALL
};

int main(){
    //printf("Hello world\n");
    //system("/bin/stty raw");
    HEIGHT = 8;
    WIDTH = 8;
    Initialize();
    PLAYER->position.x = 4;
    PLAYER->position.y = 4;
    for(int i = 0, cnt = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            SCREEN[i][j] = map[cnt]==1 ? '#' : ' ';
            if((int)PLAYER->position.y == j && PLAYER->position.x == i){SCREEN[i][j] = 'P';}
            cnt++;
        }
    }
    RenderScreen();
    //system("/bin/stty cooked");
    return 0;
}