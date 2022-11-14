#include ".MikeEngine/Engine.h"
#include ".LARK_Libraries/entity_manager.h"

int playing = 1;


void myUpdate(){

}

void myStart(){
    //LOAD_LEVEL("LEVELS/lvl1.level");
    ENTITY_SETUP();
}

int main(){
    system("/bin/stty raw");
    //LOAD_LEVEL("LEVELS/lvl1.level");
    //return 0;
    PLAYING = &playing;
    //printf("Hello world\n");
    Start(60, 30, &myStart, &myUpdate);
    system("/bin/stty cooked");
    return 0;
}