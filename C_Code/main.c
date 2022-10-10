#include "MikeEngine/Engine.h"

enum TAGS{
    DEFAULT,
    PLAYER_TAG,
    ITEM,
    WALL
};

int main(){
    printf("Hello world\n");
    system("/bin/stty raw");
    char c = getchar();
    while(c != '0'){
        putchar(c);
        c = getchar();
    }
    system("/bin/stty cooked");
    return 0;
}