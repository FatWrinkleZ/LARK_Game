#include "entity_manager.h"

char scrollText1[512] = {
    "\r\nThis is a scroll. They contain useful information to learn how to play the game.\r\nYou already know that if you walk over something, you can use './pickup.sh' to pick it up\r\nYou can also use './drop.sh' to drop it\r\nThere is also './use.sh' to use (but you already know that)"
};

char glyphText1[64]="\tThe glyph reads : 'This is a glyph'";

char susText[24] = {"You are a sussy baka"};

Transform *ROOT;
Transform *entity1;
Transform *entity2;
Transform *entity3;
Transform *entity4;
Transform *trigger;
Transform *scroll1;
Transform *lantern;
Transform *trap01;
Transform *chest;
Transform * glyph;

Transform *susScroll;

void LOG_ENTITIES(){
    for(int i = 0; i < numEntities; i++){
        fprintf(myLog, "CREATED ENTITY : [%s] with [%d] Instance ID\n", ENTITIES[i].name, ENTITIES[i].instanceID);
    }
}

void ENTITY_SETUP(){
    PLAYER->position.x = mapX/2;
    PLAYER->position.y = mapY/2;
    PLAYER->OnUpdate = (&OnPlayerUpdate);
    PLAYER->rotation = PI/2;
    PLAYER->tag = PLAYER_TAG;
    PLAYER->sprite = '$';
    PLAYER->OnUse = &ModifyHealth;
    sprintf(PLAYER->name, "PLAYER");

    entity1 = ADD_ENTITY();
    entity1->isFile = true;
    entity1->isJob = true;
    entity1->isVisible = true;
    entity1->sprite = 'K';
    entity1->position.x = 55;
    entity1->position.y = 28;
    entity1->tag = PICKUP;
    entity1->level = 2;
    entity1->OnUse = &UseKey;
    entity1->useParam = entity1;
    sprintf(entity1->name, "1.key");

    entity2 = ADD_ENTITY();
    entity2->isFile = true;
    entity2->isJob = true;
    entity2->isVisible = true;
    entity2->level = 1;
    entity2->position.x = 10;
    entity2->position.y = 10;
    entity2->sprite = 'K';
    entity2->tag = PICKUP;
    entity2->OnUse = &UseKey;
    entity2->useParam = entity2;
    sprintf(entity2->name, "2.key");

    glyph = ADD_ENTITY();
    glyph->isFile = true;
    glyph->isJob = true;
    glyph->isVisible = true;
    glyph->level = 1;
    glyph->position.x = 15;
    glyph->position.y = 2;
    glyph->sprite = 'X';
    glyph->tag = DEFAULT;
    glyph->OnInteract = &AddToTerminalOutput;
    glyph->useParam = &glyphText1;
    sprintf(glyph->name, "glyph1.glyph");

    susScroll = ADD_ENTITY();
    susScroll->isFile = false;
    susScroll->isJob = false;
    susScroll->isVisible= true;
    susScroll->level = 69;
    susScroll->sprite = '@';
    susScroll->tag = PICKUP;
    susScroll->OnUse = &WriteToTerminalOutput;
    susScroll->useParam = &susText;
    sprintf(susScroll->name, "sussy_scroll.scroll");
    susScroll->position.x = 35;
    susScroll->position.y = 20;

    entity3 = ADD_ENTITY();
    entity3->isFile = true;
    entity3->sprite = '%';
    entity3->level = 1;
    entity3->position.x = 10;
    entity3->position.y = 26;
    entity3->isVisible = true;
    entity3->tag = DOOR;
    sprintf(entity3->name, "1.door");

    entity4 = ADD_ENTITY();
    entity4->isFile = true;
    entity4->sprite = '%';
    entity4->level = 2;
    entity4->position.x = 45;
    entity4->position.y = 17;
    entity4->isVisible = true;
    entity4->tag = DOOR;
    sprintf(entity4->name, "2.door");

    scroll1 = ADD_ENTITY();
    scroll1->isFile = true;
    scroll1->isJob = false;
    scroll1->isVisible = true;
    scroll1->level = 1;
    scroll1->position.x = 10;
    scroll1->position.y = 12;
    scroll1->sprite = '@';
    scroll1->tag = PICKUP;
    scroll1->OnUse = &WriteToTerminalOutput;
    scroll1->useParam = &scrollText1;
    sprintf(scroll1->name, "basics.scroll");

    lantern = ADD_ENTITY();
    lantern->isFile = true;
    lantern->isJob = false;
    lantern->isVisible = true;
    lantern->level = 1;
    lantern->position.x = 10;
    lantern->position.y = 8;
    lantern->sprite = '*';
    lantern->tag = PICKUP;
    lantern->OnUse = &UseLantern;
    sprintf(lantern->name, "lantern.light");

    chest = ADD_ENTITY();
    chest->isFile = true;
    chest->isJob = false;
    chest->isVisible = true;
    chest->level = 1;
    chest->position.x = 34;
    chest->position.y = 16;
    chest->sprite = 'X';
    chest->tag = DEFAULT;
    chest->OnInteract = &OpenChest;
    sprintf(chest->name, "chest.container");

    trap01 = ADD_ENTITY();
    trap01->isFile = false;
    trap01->isJob = false;
    trap01->isVisible = false;
    trap01->level = 1;
    trap01->position.x = 29;
    trap01->position.y = 19;
    trap01->sprite = 'T';
    trap01->tag = TRAP;
    trap01->OnUpdate = &TriggerTrap;
    sprintf(trap01->name, ".spike_lvl1.trap");

    trigger = ADD_ENTITY();
    trigger->isFile = false;
    trigger->sprite = ' ';
    trigger->level = 1;
    trigger->position.x = 22;
    trigger->position.y = 9;
    trigger->isVisible = false;
    trigger->tag = DEFAULT;
    trigger->OnUpdate = &TriggerUpdate;
    sprintf(trigger->name, "You enter a dark room");

    LOG_ENTITIES();
}

