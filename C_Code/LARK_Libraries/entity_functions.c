#include "entity_functions.h"

void TriggerUpdate(Transform* this){
    if((int)this->position.x == (int)PLAYER->position.x && (int)this->position.y == (int)PLAYER->position.y){
        WriteToTerminalOutput(this->name);
    }
}

void WriteToTerminalOutput(char* str){
    sprintf(terminalOutput, "%s", str);
}

void SetActive(Transform* t, bool active){
    t->ALIVE = active;
}