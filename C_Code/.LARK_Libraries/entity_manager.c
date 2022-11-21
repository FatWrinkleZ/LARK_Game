#include "entity_manager.h"

char scrollText1[512] = {
    "\r\nThis is a scroll. They contain useful information to learn how to play the game.\r\nYou already know that if you walk over something, you can use './pickup.sh' to pick it up\r\nYou can also use './drop.sh' to drop it\r\nThere is also './use.sh' to use (but you already know that)"
};

char glyphText1[64]="\tThe glyph reads : 'This is a glyph'";

char susText[24] = {"You are a sussy baka"};

//char added 

char scroll1lvl6TEXT[72]={"Explore The Caves To Uncover All The Scrolls Of Forbidden Knowledge."};

char scroll2lvl6TEXT[64]={"Check out the most sane man in human history: level 70 secret"};

char scroll3lvl6TEXT[24]={"WE NEED TO COOK: level 71 secret"};

char scroll4lvl6TEXT[48]={"Based. : Level 72 secret "};

char scroll5lvl6TEXT[72]={"Go ahead. Nothing omnious at all about this one: Level 73 secret"}; 

char scroll6lvl6TEXT[24]={"Soldier: Level 74 secret"};

char lvl70glyphText1[8]="sus.";

char lvl71triggerText1[16]="el heisenberg"; 

char lvl5GlyphText1[48]={"DANGER AHEAD, prepare for damage!"}; 

char glyph1lvl6TEXT[72]={"levels hidden ahead are of a certain hidden file type, a S E C R E T one."};
//Level 5 
Transform* triggerXlvl5; 

Transform* key1lvl5; 

Transform* chest1lvl5; 
Transform* chest2lvl5; 
Transform* chest3lvl5; 
Transform* torch1lvl5; 
Transform* glyph1lvl5; 
Transform* trap1lvl5; 
Transform* trap2lvl5; 
Transform* trap3lvl5; 
Transform* trap4lvl5; 
Transform* trap5lvl5; 
Transform* trap6lvl5; 
Transform* trap7lvl5;
//level 6 
Transform* scroll1lvl6;
Transform* scroll2lvl6; 
Transform* scroll3lvl6; 
Transform* scroll4lvl6; 
Transform* scroll5lvl6; 
Transform* scroll6lvl6; 
Transform* triggerStartlvl6; 
Transform* glyph1lvl6; 


//secret levels
Transform* lvl69trigger1;
Transform* lvl70glyph1;
Transform* lvl70trigger1;
Transform* lvl70gas1; 
Transform* lvl70gasTrigger1; 
Transform* lvl71trigger1; 
Transform* lvl71trigger2; 
Transform* lvl71trigger3; 
Transform* lvl72trigger1; 
Transform* lvl72trigger2; 
Transform* lvl73trigger1; 
Transform* lvl73trigger2;
Transform* lvl74trigger1; 
Transform* lvl74trigger2;
//entity_manager.h
//secret levels 


Transform *ROOT;

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

    //trigger for level 69 
    lvl69trigger1=ADD_ENTITY(); 
    lvl69trigger1->isFile=false; 
    lvl69trigger1->sprite=' '; 
    lvl69trigger1->level=69; 
    lvl69trigger1->position.x=40; 
    lvl69trigger1->position.y=20; 
    lvl69trigger1->isVisible=false; 
    lvl69trigger1->tag=DEFAULT; 
    lvl69trigger1->OnUpdate = &TriggerUpdate; 
    sprintf(lvl69trigger1->name,"There is a imposter among us."); 

   
    //glyph 1 on level 70 (secret)
    lvl70glyph1=ADD_ENTITY(); 
    lvl70glyph1->isFile=true; 
    lvl70glyph1->isJob=true;
    lvl70glyph1->isVisible=true; 
    lvl70glyph1->level=70; 
    lvl70glyph1->position.x=51;
    lvl70glyph1->position.y=22; 
    lvl70glyph1->sprite='M';
    lvl70glyph1->tag=DEFAULT;
    lvl70glyph1->OnInteract=&AddToTerminalOutput; 
    lvl70glyph1->useParam=&lvl70glyphText1; 
    sprintf(lvl70glyph1->name,"lvl70glyph1.glyph"); 

    //trigger 1 on level 70 (Secret) 
    lvl70trigger1=ADD_ENTITY();
    lvl70trigger1->isFile=false; 
    lvl70trigger1->sprite=' ';
    lvl70trigger1->level = 70; 
    lvl70trigger1->position.x=50; 
    lvl70trigger1->position.y=28; 
    lvl70trigger1->isVisible=false; 
    lvl70trigger1->tag=DEFAULT; 
    lvl70trigger1->OnUpdate=&TriggerUpdate; 
    sprintf(lvl70trigger1->name, "when the player arises suspicion"); 

    //gas trap
    lvl70gas1=ADD_ENTITY(); 
    lvl70gas1->isFile =false; 
    lvl70gas1->isJob = false; 
    lvl70gas1->isVisible = true; 
    lvl70gas1->level = 70; 
    lvl70gas1->position.x=54; 
    lvl70gas1->position.y=27;
    lvl70gas1->sprite='G'; 
    lvl70gas1->tag=TRAP; 
    lvl70gas1->OnUpdate=&TriggerTrap; 
    sprintf(lvl70gas1->name, ".lvl70gas1.trap"); 

    //gas trigger level 70 (secret)
    lvl70gasTrigger1=ADD_ENTITY();
    lvl70gasTrigger1->isFile=false; 
    lvl70gasTrigger1->sprite=' ';
    lvl70gasTrigger1->level=70; 
    lvl70gasTrigger1->position.x=54;
    lvl70gasTrigger1->position.y=27; 
    lvl70gasTrigger1->isVisible=false; 
    lvl70gasTrigger1->tag=DEFAULT; 
    lvl70gasTrigger1->OnUpdate=&TriggerUpdate; 
    sprintf(lvl70gasTrigger1->name, "GAS GAS GAS THE ROOM WILL FILL WITH GAS GAS GAS ");  



    //popup message level 71 (secret) 
    lvl71trigger1=ADD_ENTITY(); 
    lvl71trigger1->isFile=false; 
    lvl71trigger1->sprite=' '; 
    lvl71trigger1->level=71; 
    lvl71trigger1->position.x = 40; 
    lvl71trigger1->position.y = 21; 
    lvl71trigger1->isVisible=false; 
    lvl71trigger1->tag=DEFAULT; 
    lvl71trigger1->OnUpdate=&TriggerUpdate; 
    sprintf(lvl71trigger1->name, "el heisenberg");

    //trigger message 2 level 71 (secret) 
    lvl71trigger2=ADD_ENTITY(); 
    lvl71trigger2->isFile=false; 
    lvl71trigger2->sprite=' '; 
    lvl71trigger2->level=71; 
    lvl71trigger2->position.x = 37; 
    lvl71trigger2->position.y = 4; 
    lvl71trigger2->isVisible=false; 
    lvl71trigger2->tag=DEFAULT; 
    lvl71trigger2->OnUpdate=&TriggerUpdate; 
    sprintf(lvl71trigger2->name, "HOLY MOTHER OF GOD");

    //trigger message 3 level 71 (secret) 
    lvl71trigger3=ADD_ENTITY(); 
    lvl71trigger3->isFile=false; 
    lvl71trigger3->sprite=' '; 
    lvl71trigger3->level=71; 
    lvl71trigger3->position.x = 61; 
    lvl71trigger3->position.y = 32; 
    lvl71trigger3->isVisible=false; 
    lvl71trigger3->tag=DEFAULT; 
    lvl71trigger3->OnUpdate=&TriggerUpdate; 
    sprintf(lvl71trigger3->name, "JESSE!");

    //trigger 1 on level 72 (secret )
    lvl72trigger1=ADD_ENTITY(); 
    lvl72trigger1->isFile=false; 
    lvl72trigger1->sprite=' '; 
    lvl72trigger1->level=72; 
    lvl72trigger1->position.x=24; 
    lvl72trigger1->position.y=33; 
    lvl72trigger1->isVisible=false; 
    lvl72trigger1->tag=DEFAULT; 
    lvl72trigger1->OnUpdate=&TriggerUpdate; 
    sprintf(lvl72trigger1->name, "feels good man"); 

    //trigger 2 on level 72 (secret )
    lvl72trigger2=ADD_ENTITY(); 
    lvl72trigger2->isFile=false; 
    lvl72trigger2->sprite=' '; 
    lvl72trigger2->level=72; 
    lvl72trigger2->position.x=41; 
    lvl72trigger2->position.y=9; 
    lvl72trigger2->isVisible=false; 
    lvl72trigger2->tag=DEFAULT; 
    lvl72trigger2->OnUpdate=&TriggerUpdate; 
    sprintf(lvl72trigger2->name, "feels bad man"); 

    //level 73 trigger 1 
    lvl73trigger1=ADD_ENTITY(); 
    lvl73trigger1->isFile= false; 
    lvl73trigger1->sprite=' '; 
    lvl73trigger1->level=73; 
    lvl73trigger1->position.x=11; 
    lvl73trigger1->position.y=32; 
    lvl73trigger1->isVisible=false;
    lvl73trigger1->tag=DEFAULT; 
    lvl73trigger1->OnUpdate=&TriggerUpdate; 
    sprintf(lvl73trigger1->name, "\"We do a little trolling, it's called we do a little trolling.\""); 

    //level 73 trigger 2
    lvl73trigger2=ADD_ENTITY(); 
    lvl73trigger2->isFile=false; 
    lvl73trigger2->sprite=' '; 
    lvl73trigger2->level=73; 
    lvl73trigger2->position.x=11; 
    lvl73trigger2->position.y=32; 
    lvl73trigger2->isVisible=false;
    lvl73trigger2->tag=DEFAULT; 
    lvl73trigger2->OnUpdate=&TriggerUpdate; 
    sprintf(lvl73trigger2->name, "\"We do a little trolling, it's called we do a little trolling.\""); 

    //level 74 trigger 1 
    lvl74trigger1=ADD_ENTITY(); 
    lvl74trigger1->isFile=false; 
    lvl74trigger1->sprite=' ';
    lvl74trigger1->level=74; 
    lvl74trigger1->position.x=42; 
    lvl74trigger1->position.y= 6; 
    lvl74trigger1->isVisible=false; 
    lvl74trigger1->tag=DEFAULT; 
    lvl74trigger1->OnUpdate=&TriggerUpdate; 
    sprintf(lvl74trigger1->name, "Beautiful Smile"); 

    //level 74 trigger 2 
    lvl74trigger2=ADD_ENTITY(); 
    lvl74trigger2->isFile=false; 
    lvl74trigger2->sprite=' ';
    lvl74trigger2->level=74; 
    lvl74trigger2->position.x=53; 
    lvl74trigger2->position.y= 30; 
    lvl74trigger2->isVisible=false; 
    lvl74trigger2->tag=DEFAULT; 
    lvl74trigger2->OnUpdate=&TriggerUpdate; 
    sprintf(lvl74trigger2->name, "Indomitable Human Spirit"); 
    triggerXlvl5 = ADD_ENTITY(); 
    triggerXlvl5->isFile = false; 
    triggerXlvl5->sprite = ' ';
    triggerXlvl5->level = 5; 
    triggerXlvl5->position.x=5;
    triggerXlvl5->position.y=32; 
    triggerXlvl5->isVisible = false;
    triggerXlvl5->tag=DEFAULT; 
    triggerXlvl5->OnUpdate = &TriggerUpdate; 
    sprintf(triggerXlvl5->name, "This seems to be part of a bigger picture. "); 


 //keyforlvl1inlvl5 (final password door key part 1)
   
   key1lvl5 = ADD_ENTITY(); 
    key1lvl5->isFile = true ;
    key1lvl5->isJob = true; 
    key1lvl5->ALIVE; 
   key1lvl5->sprite = 'K'; 
   key1lvl5->level = 5; 
    key1lvl5->position.x = 58; 
    key1lvl5->position.y = 17; 
    key1lvl5->isVisible = true; 
   key1lvl5-> tag = PICKUP; 
    key1lvl5->OnUse = &UseKey; 
    key1lvl5 -> useParam = key1lvl5; 
    sprintf(key1lvl5->name,"3.key"); 

    //chest behind key level 5 
    chest1lvl5=ADD_ENTITY(); 
    chest1lvl5-> isFile = true; 
     chest1lvl5-> isJob = false; 
      chest1lvl5-> isVisible = true; 
       chest1lvl5-> level=5; 
        chest1lvl5-> position.x=58; 
         chest1lvl5-> position.y=18 ;
          chest1lvl5-> sprite = 'X'; 
           chest1lvl5-> tag = DEFAULT; 
            chest1lvl5-> OnInteract = &OpenChest; 
            sprintf( chest1lvl5-> name, "chest1lvl5.container"); 

    chest2lvl5=ADD_ENTITY(); 
    chest2lvl5-> isFile = true; 
    chest2lvl5-> isJob = false; 
    chest2lvl5-> isVisible = true; 
    chest2lvl5-> level=5; 
    chest2lvl5-> position.x=57; 
    chest2lvl5-> position.y=14 ;
    chest2lvl5-> sprite = 'X'; 
    chest2lvl5-> tag = DEFAULT; 
    chest2lvl5-> OnInteract = &OpenChest; 
    sprintf( chest2lvl5-> name, "chest2lvl5.container"); 

 chest3lvl5=ADD_ENTITY(); 
    chest3lvl5-> isFile = true; 
    chest3lvl5-> isJob = false; 
    chest3lvl5-> isVisible = true; 
    chest3lvl5-> level=5; 
    chest3lvl5-> position.x=59; 
    chest3lvl5-> position.y=14 ;
    chest3lvl5-> sprite = 'X'; 
    chest3lvl5-> tag = DEFAULT; 
    chest3lvl5-> OnInteract = &OpenChest; 
    sprintf( chest3lvl5-> name, "chest3lvl5.container"); 

    //glyph level 5 near key 
    glyph1lvl5 = ADD_ENTITY(); 
    glyph1lvl5-> isFile = true; 
    glyph1lvl5-> isJob=true; 
    glyph1lvl5-> isVisible = true; 
    glyph1lvl5-> level=5; 
    glyph1lvl5-> position.x=58; 
    glyph1lvl5-> position.y=12; 
    glyph1lvl5->  sprite = 'M'; 
    glyph1lvl5-> tag = DEFAULT; 
    glyph1lvl5-> OnInteract = &AddToTerminalOutput; 
    glyph1lvl5-> useParam = &lvl5GlyphText1; 
    sprintf(glyph1lvl5->name, "glyphlvl5.glyph"); 

    //torch level 5 near key 
    torch1lvl5=ADD_ENTITY(); 
    torch1lvl5->isFile = true; 
    torch1lvl5->isJob =false; 
    torch1lvl5->isVisible=true; 
    torch1lvl5->level=5; 
    torch1lvl5->position.x = 58; 
    torch1lvl5->position.y = 11;
    torch1lvl5->sprite='*';
    torch1lvl5->tag= PICKUP; 
    torch1lvl5->OnUse=&UseLantern; 
    sprintf(torch1lvl5->name, "lvl5torch.light"); 

    //traps level 5 
    trap1lvl5 = ADD_ENTITY(); 
    trap1lvl5-> isFile = false; 
    trap1lvl5-> isJob = false; 
    trap1lvl5-> isVisible =false; 
    trap1lvl5-> level = 5; 
    trap1lvl5-> position.x=57; 
    trap1lvl5-> position.y=16;
    trap1lvl5-> sprite = 'T';
    trap1lvl5-> tag = TRAP; 
    trap1lvl5-> OnUpdate = &TriggerTrap ;
    sprintf(trap1lvl5-> name, ".lvl5trap1.trap"); 

    trap2lvl5 = ADD_ENTITY(); 
    trap2lvl5-> isFile = false; 
    trap2lvl5-> isJob = false; 
    trap2lvl5-> isVisible =false; 
    trap2lvl5-> level = 5; 
    trap2lvl5-> position.x=58; 
    trap2lvl5-> position.y=16;
    trap2lvl5-> sprite = 'T';
    trap2lvl5-> tag = TRAP; 
    trap2lvl5-> OnUpdate = &TriggerTrap ;
    sprintf(trap2lvl5-> name, ".lvl5trap2.trap"); 


    trap3lvl5 = ADD_ENTITY(); 
    trap3lvl5-> isFile = false; 
    trap3lvl5-> isJob = false; 
    trap3lvl5-> isVisible =false; 
    trap3lvl5-> level = 5; 
    trap3lvl5-> position.x=59; 
    trap3lvl5-> position.y=16;
    trap3lvl5-> sprite = 'T';
    trap3lvl5-> tag = TRAP; 
    trap3lvl5-> OnUpdate = &TriggerTrap ;
    sprintf(trap3lvl5-> name, ".lvl5trap3.trap"); 

     trap4lvl5 = ADD_ENTITY(); 
    trap4lvl5-> isFile = false; 
    trap4lvl5-> isJob = false; 
    trap4lvl5-> isVisible =false; 
    trap4lvl5-> level = 5; 
    trap4lvl5-> position.x=57; 
    trap4lvl5-> position.y=17;
    trap4lvl5-> sprite = 'T';
    trap4lvl5-> tag = TRAP; 
    trap4lvl5-> OnUpdate = &TriggerTrap ;
    sprintf(trap4lvl5-> name, ".lvl5trap4.trap"); 

    trap5lvl5 = ADD_ENTITY(); 
    trap5lvl5-> isFile = false; 
    trap5lvl5-> isJob = false; 
    trap5lvl5-> isVisible =false; 
    trap5lvl5-> level = 5; 
    trap5lvl5-> position.x=57; 
    trap5lvl5-> position.y=18;
    trap5lvl5-> sprite = 'T';
    trap5lvl5-> tag = TRAP; 
    trap5lvl5-> OnUpdate = &TriggerTrap ;
    sprintf(trap5lvl5-> name, ".lvl5trap5.trap"); 


    trap6lvl5 = ADD_ENTITY(); 
    trap6lvl5-> isFile = false; 
    trap6lvl5-> isJob = false; 
    trap6lvl5-> isVisible =false; 
    trap6lvl5-> level = 5; 
    trap6lvl5-> position.x=59; 
    trap6lvl5-> position.y=17;
    trap6lvl5-> sprite = 'T';
    trap6lvl5-> tag = TRAP; 
    trap6lvl5-> OnUpdate = &TriggerTrap ;
    sprintf(trap6lvl5-> name, ".lvl5trap6.trap"); 

    trap7lvl5 = ADD_ENTITY(); 
    trap7lvl5-> isFile = false; 
    trap7lvl5-> isJob = false; 
    trap7lvl5-> isVisible =false; 
    trap7lvl5-> level = 5; 
    trap7lvl5-> position.x=59; 
    trap7lvl5-> position.y=18;
    trap7lvl5-> sprite = 'T';
    trap7lvl5-> tag = TRAP; 
    trap7lvl5-> OnUpdate = &TriggerTrap ;
    sprintf(trap7lvl5-> name, ".lvl5trap7.trap"); 
    //Origin Trigger 
    triggerStartlvl6= ADD_ENTITY(); 
    triggerStartlvl6->isFile = false; 
    triggerStartlvl6->sprite= ' '; 
    triggerStartlvl6->level = 6; 
    triggerStartlvl6->position.x=30; 
    triggerStartlvl6->position.y=22; 
    triggerStartlvl6->isVisible = false;
    triggerStartlvl6->tag=DEFAULT;
    triggerStartlvl6->OnUpdate = &TriggerUpdate; 
    sprintf(triggerStartlvl6->name, "Your Adventure Doesn't Have To Be Over Yet!"); 

    //Origin Scroll 
    scroll1lvl6=ADD_ENTITY(); 
    scroll1lvl6->isFile = true; 
    scroll1lvl6->isJob = false; 
    scroll1lvl6->isVisible=true; 
    scroll1lvl6->level = 6; 
    scroll1lvl6->position.x=30; 
    scroll1lvl6->position.y=19;
    scroll1lvl6->sprite='@';
    scroll1lvl6->tag = PICKUP; 
    scroll1lvl6->OnUse = &WriteToTerminalOutput; 
    scroll1lvl6->useParam=&scroll1lvl6TEXT;
    sprintf(scroll1lvl6->name, "ExploreLevel6.scroll");

    //secret scroll 1 
    scroll2lvl6=ADD_ENTITY(); 
    scroll2lvl6->isFile = true; 
    scroll2lvl6->isJob = false; 
    scroll2lvl6->isVisible=true; 
    scroll2lvl6->level = 6; 
    scroll2lvl6->position.x=13; 
    scroll2lvl6->position.y=32;
    scroll2lvl6->sprite='@';
    scroll2lvl6->tag = PICKUP; 
    scroll2lvl6->OnUse = &WriteToTerminalOutput; 
    scroll2lvl6->useParam=&scroll2lvl6TEXT;
    sprintf(scroll2lvl6->name, "SecretScroll1.scroll");

     //secret scroll 2 
    scroll3lvl6=ADD_ENTITY(); 
    scroll3lvl6->isFile = true; 
    scroll3lvl6->isJob = false; 
    scroll3lvl6->isVisible=true; 
    scroll3lvl6->level = 6; 
    scroll3lvl6->position.x=47; 
    scroll3lvl6->position.y=15;
    scroll3lvl6->sprite='@';
    scroll3lvl6->tag = PICKUP; 
    scroll3lvl6->OnUse = &WriteToTerminalOutput; 
    scroll3lvl6->useParam=&scroll3lvl6TEXT;
    sprintf(scroll3lvl6->name, "SecretScroll2.scroll");

      //secret scroll 3
    scroll4lvl6=ADD_ENTITY(); 
    scroll4lvl6->isFile = true; 
    scroll4lvl6->isJob = false; 
    scroll4lvl6->isVisible=true; 
    scroll4lvl6->level = 6; 
    scroll4lvl6->position.x=44; 
    scroll4lvl6->position.y=25;
    scroll4lvl6->sprite='@';
    scroll4lvl6->tag = PICKUP; 
    scroll4lvl6->OnUse = &WriteToTerminalOutput; 
    scroll4lvl6->useParam=&scroll4lvl6TEXT;
    sprintf(scroll4lvl6->name, "SecretScroll3.scroll");

      //secret scroll 4
    scroll4lvl6=ADD_ENTITY(); 
    scroll4lvl6->isFile = true; 
    scroll4lvl6->isJob = false; 
    scroll4lvl6->isVisible=true; 
    scroll4lvl6->level = 6; 
    scroll4lvl6->position.x=56; 
    scroll4lvl6->position.y=43;
    scroll4lvl6->sprite='@';
    scroll4lvl6->tag = PICKUP; 
    scroll4lvl6->OnUse = &WriteToTerminalOutput; 
    scroll4lvl6->useParam=&scroll4lvl6TEXT;
    sprintf(scroll4lvl6->name, "SecretScroll4.scroll"); 

      //secret scroll 5 
    scroll5lvl6=ADD_ENTITY(); 
    scroll5lvl6->isFile = true; 
    scroll5lvl6->isJob = false; 
    scroll5lvl6->isVisible=true; 
    scroll5lvl6->level = 6; 
    scroll5lvl6->position.x=20; 
    scroll5lvl6->position.y=15;
    scroll5lvl6->sprite='@';
    scroll5lvl6->tag = PICKUP; 
    scroll5lvl6->OnUse = &WriteToTerminalOutput; 
    scroll5lvl6->useParam=&scroll5lvl6TEXT;
    sprintf(scroll5lvl6->name, "SecretScroll5.scroll");  

        //secret scroll 5 
    scroll6lvl6=ADD_ENTITY(); 
    scroll6lvl6->isFile = true; 
    scroll6lvl6->isJob = false; 
    scroll6lvl6->isVisible=true; 
    scroll6lvl6->level = 6; 
    scroll6lvl6->position.x=13; 
    scroll6lvl6->position.y=32;
    scroll6lvl6->sprite='@';
    scroll6lvl6->tag = PICKUP; 
    scroll6lvl6->OnUse = &WriteToTerminalOutput; 
    scroll6lvl6->useParam=&scroll6lvl6TEXT;
    sprintf(scroll6lvl6->name, "SecretScroll6.scroll");  

    //glyph for level 6 
    glyph1lvl6=ADD_ENTITY(); 
    glyph1lvl6->isFile=true; 
    glyph1lvl6->isJob=true; 
    glyph1lvl6->isVisible=true; 
    glyph1lvl6->level=6; 
    glyph1lvl6->position.x=30; 
    glyph1lvl6->position.y=24; 
    glyph1lvl6->sprite='M'; 
    glyph1lvl6->tag=DEFAULT; 
    glyph1lvl6->OnInteract=&AddToTerminalOutput;
    glyph1lvl6->useParam=&glyph1lvl6TEXT;
    sprintf(glyph1lvl6->name, "glyphlvl6.glyph"); 

    LOG_ENTITIES();
}

