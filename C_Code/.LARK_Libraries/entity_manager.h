#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include "Player.h"
#include "entity_functions.h"

enum TAGS{
    DEFAULT,
    PLAYER_TAG,
    PICKUP,
    DOOR,
    TRAP
};

extern char glyphText1[64];
extern char scrollText1[512];

extern Transform *ROOT;

extern Transform* triggerXlvl5; 
extern Transform* key1lvl5; 

extern Transform* chest1lvl5; 
extern Transform* chest2lvl5; 
extern Transform* chest3lvl5; 
extern Transform* torch1lvl5; 
extern Transform* glyph1lvl5; 
extern Transform* trap1lvl5; 
extern Transform* trap2lvl5; 
extern Transform* trap3lvl5; 
extern Transform* trap4lvl5; 
extern Transform* trap5lvl5; 
extern Transform* trap6lvl5; 
extern Transform* trap7lvl5; 


//level 6 
extern char scroll1lvl6TEXT[72];
extern char scroll2lvl6TEXT[64];
extern char scroll3lvl6TEXT[24];
extern char scroll4lvl6TEXT[48];
extern char scroll5lvl6TEXT[72];
extern char scroll6lvl6TEXT[24];
extern char lvl70glyphText1[8];
extern char lvl71triggerText1[16];
extern char lvl5GlyphText1[48];
extern char glyph1lvl6TEXT[72];

//logs all entities
void LOG_ENTITIES();

//sets up basic entities
void ENTITY_SETUP();

#endif