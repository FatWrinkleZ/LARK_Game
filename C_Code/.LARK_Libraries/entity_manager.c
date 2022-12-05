#include "entity_manager.h"

char scrollText1[512] = {
    "\r\nTUTORIAL OF UNIX COMMANDS\r\nUse 'ls' to see all the 'files' in the game\r\nUse 'cd' to go to other levels EXAMPLE: 'cd lvl1.level'\r\nUse 'cat' to find the stats of a file EXAMPLE: 'cat 1.key'\r\nUse 'echo' to output your thoughts into the terminal\r\nUse 'man' to see all the commands you can use and their descriptions.\r\nThats the basics. Experiment!\r\nGood luck!"
};

char scrollText2[512] = {
    "\r\nYou find a note. It has scribbles of a penguin drawing as well as some writing.\r\nIt reads: 'Ive lost count of the days. Ive stepped on so many traps I cant move anymore.\r\nI dont feel my legs. I cant even see my legs... wait where are my legs?'\r\nThe rest is illegible.\r\nNow that you think about it: You cant see your legs either."
};
char scrollText3[32] = {
    "\r\n'cd lvl1993.secret'"
};
char scrollText4[256] = {
    "You find a piece of paper... it feels like paper\r\n'I keep seeing bits and bites of penguins...'\r\nThere's no more writing.\r\nYou look at the back of the 'paper' and you read 'cd lvl4.secret'"
};

char scrollText5[1024] = {
    "You feel a stream of 0s and 1s coming into your brain.\r\nThe penguin speaks to you.\r\n'I am tux. As you can tell, you're trapped inside of a Linux computer.'\r\nYou feel welcome yet overwhelmed by their presence\r\n'You will need this key to get out of the simulation.'\r\n'Whenever you feel lost, keep going. Doors will open themselves to you.'\r\n'Theres a reason you don't see windows around here.'\r\nIt looks at you, waiting for you to pick up the key and get going.(hint [cd lvl1.level] to get back to level 1)"
};

//Level 2 text
char scroll1lvl2text[96]={"There's a bit of a draft in here, making the room a little cold. This must be the CPU fan"};

char scroll2lvl2text[88]={"This path has to be here for a reason. I wonder if something will be here later..."};

char scroll3lvl2text[128]={"This is the second of these strange letters in this area. They're definitely spelling something out, but what could it be?"};

char glyph1lvl2text[80]={"The letters on this glyph are unreadable. Maybe they can be read somewhere else"};

char glyph2lvl2text[64]={"It seems there's a logo here. The text on it says \"HorseAir\""};

char glyph3lvl2text[24]={"CAUTION: WATCH YOUR STEP"};

char glyphText1[128]="\r\nTraps ahead. ./use.sh of lantern '*' recommended for better visibility.";
char glyphText2[512]="\r\nThree massive doors lay in front of you, each to their own room. Something tells you that the code to the exit hides behind them.\r\nWhy? You dont know why.";
char glyphText4[256]="\r\nYou find a vent on this corner. Thats odd...\r\nYou open the vent and see a note.\r\n'cd lvl69.secret'\r\n...\r\noh lord'";
char glyphText0[256]="\r\nThe writing on the wall reads 'Tux'\r\n...\r\nThats a little underwhelming.\r\nIt seems important though... Maybe the other doors have more answers\r\nI think there's nothing else to do here though... Maybe checking other levels out will help.";
char glyphText9[128]="\r\nThis time the wall reads 'Torvalds'\r\nOne more door and all will be revealed";
char glyphText8[256]="\r\nYou see a bunch of 0s and 1s but for some reason you can read it\r\nIt says '1991'\r\n'become su by combining your 3 passcodes and exit out'\r\nYou finally know what to do.";
char glyphText10[1024]="\r\nHey! Developer speaking here.\r\nOriginally this game started as a doom inspired game\r\nIt had the same first person view and we wanted to use it as a maze\r\nBut we had to change course when we realized it wasnt very fun\r\nWe went with top view because the debugger of the doom view looked like what youre playing right now :)\r\nThats all though so developer out! Thank you for playing our game <3\0";

char susText[24] = {"You are a sussy baka"};

//char added 

char scroll1lvl6TEXT[72]={"Explore The Caves To Uncover All The Scrolls Of Forbidden Knowledge."};

char scroll2lvl6TEXT[64]={"Check out the most sane man in human history: level 70 secret"};

char scroll3lvl6TEXT[48]={"WE NEED TO COOK: level 71 secret"};

char scroll4lvl6TEXT[48]={"Based. : Level 72 secret "};

char scroll5lvl6TEXT[72]={"Go ahead. Nothing omnious at all about this one: Level 73 secret"}; 

char scroll6lvl6TEXT[24]={"Soldier: Level 74 secret"};

char lvl70glyphText1[8]="sus.";

char lvl71triggerText1[16]="el heisenberg"; 

char lvl5GlyphText1[48]={"DANGER AHEAD, prepare for damage!"}; 

char glyph1lvl6TEXT[72]={"levels hidden ahead are of a certain hidden file type, a S E C R E T one."};

//Level 3 text
char scroll1lvl3text[72]={"This area seems a little familiar. If only I could get through the door"};

char scroll2lvl3text[80]={"Some things are in the same places, but others have moved around. I wonder why"};

char scroll3lvl3text[56]={"That bite in the wall... Someone must've been hungry"};

char glyph1lvl3text[32]={"nom nom nom walls tasty :D"};

char glyph2lvl3text[80]={"The letters on this glyph are unreadable. Maybe they can be read somewhere else"};
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
Transform *trigger1lvl1;
Transform *trigger2lvl1;
Transform *trigger3lvl1;
Transform *trigger5lvl1;
Transform *trigger6lvl1;
    //keys and doors
Transform *key1lvl1;
Transform *key2lvl1;
Transform *key4lvl1;
Transform *key5lvl1;
Transform *key0lvl1;
Transform *key8lvl1;
Transform *door1lvl1;
Transform *door2lvl1;
Transform *door4lvl1;
Transform *door5lvl1;
Transform *door52lvl1;
        //final doors
Transform *door0lvl1;
Transform *door9lvl1;
Transform *door8lvl1;
    //scrolls and glyphs
Transform *scroll1lvl1;
Transform *scroll2lvl1;
Transform *scroll3lvl1;
Transform *scroll4lvl1;
Transform *scroll5lvl1;
Transform *glyph1;
Transform *glyph2;
Transform *glyph3;
Transform *glyph4;
Transform *glyph0;
Transform *glyph9;
Transform *glyph8;
    //lanters, chests and traps
Transform *lantern1;
Transform *lantern2;
Transform *chest;
Transform *chest2;
Transform *chest3;
Transform *chest4;
Transform *trap1;
Transform *trap2;
Transform *trap3;
Transform *trap4;
Transform *trap5;
Transform *trap6;
Transform *trap7;
Transform *trap8;
Transform *trap9;
Transform *trap10;
Transform *trap11;
Transform *trap12;
//Level2
Transform *entity2;
Transform *entity3;
//secret levels
Transform *glyph10;


Transform *ROOT;

Transform *susScroll;

//Level 2
Transform* key1lvl2;
Transform* key2lvl2;
Transform* key3lvl2;
Transform* door1lvl2;
Transform* door2lvl2;
Transform* scroll1lvl2;
Transform* scroll2lvl2;
Transform* scroll3lvl2;
Transform* glyph1lvl2;
Transform* glyph2lvl2;
Transform* glyph3lvl2;
Transform* triggerlvl2;
Transform* trap1lvl2;
Transform* trap2lvl2;
Transform* trap3lvl2;
Transform* trap4lvl2;
Transform* chest1lvl2;
Transform* chest2lvl2;
Transform* chest3lvl2;
Transform* chest4lvl2;
Transform* lanternlvl2;

//Level 3
Transform* key1lvl3;
Transform* key2lvl3;
Transform* door1lvl3;
Transform* door2lvl3;
Transform* scroll1lvl3;
Transform* scroll2lvl3;
Transform* scroll3lvl3;
Transform* glyph1lvl3;
Transform* glyph2lvl3;
Transform* glyph3lvl3;
Transform* triggerlvl3;
Transform* trap1lvl3;
Transform* trap2lvl3;
Transform* trap3lvl3;
Transform* trap4lvl3;
Transform* chest1lvl3;
Transform* chest2lvl3;
Transform* chest3lvl3;
Transform* chest4lvl3;
Transform* lanternlvl3;


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
    sprintf(key1lvl5->name,"9.key"); 

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

    trigger1lvl1 = ADD_ENTITY();
    trigger1lvl1->isFile = false;
    trigger1lvl1->isJob= false;
    trigger1lvl1->sprite = ' ';
    trigger1lvl1->level = 1;
    trigger1lvl1->position.x = 30;
    trigger1lvl1->position.y = 16;
    trigger1lvl1->isVisible = false;
    trigger1lvl1->tag = DEFAULT;
    trigger1lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger1lvl1->name, "You're finally awake. Its a cozy corner to wake up in.");
        //L room lol
    trigger2lvl1 = ADD_ENTITY();
    trigger2lvl1->isFile = false;
    trigger2lvl1->isJob= false;
    trigger2lvl1->sprite = ' ';
    trigger2lvl1->level = 1;
    trigger2lvl1->position.x = 29;
    trigger2lvl1->position.y = 20;
    trigger2lvl1->isVisible = false;
    trigger2lvl1->tag = DEFAULT;
    trigger2lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger2lvl1->name, "There is a big L in this room. I wonder what that could stand for?");
        //hallway!
    trigger3lvl1 = ADD_ENTITY();
    trigger3lvl1->isFile = false;
    trigger3lvl1->isJob= false;
    trigger3lvl1->sprite = ' ';
    trigger3lvl1->level = 1;
    trigger3lvl1->position.x = 34;
    trigger3lvl1->position.y = 21;
    trigger3lvl1->isVisible = false;
    trigger3lvl1->tag = DEFAULT;
    trigger3lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger3lvl1->name, "\r\nThis hallway feels infinitely long! ...until it isnt.\r\nYou see a room with a locked door.\r\nIt looks like a bunch of circuits.");

        //Chest room! to the right of the trap room
    trigger5lvl1 = ADD_ENTITY();
    trigger5lvl1->isFile = false;
    trigger5lvl1->isJob= false;
    trigger5lvl1->sprite = ' ';
    trigger5lvl1->level = 1;
    trigger5lvl1->position.x = 48;
    trigger5lvl1->position.y = 26;
    trigger5lvl1->isVisible = false;
    trigger5lvl1->tag = DEFAULT;
    trigger5lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger5lvl1->name, "You spot a chest across the room. Inspecting chests heals your health.\r\nCould be useful...");

    trigger6lvl1 = ADD_ENTITY();
    trigger6lvl1->isFile = false;
    trigger6lvl1->isJob= false;
    trigger6lvl1->sprite = ' ';
    trigger6lvl1->level = 1;
    trigger6lvl1->position.x = 37;
    trigger6lvl1->position.y = 5;
    trigger6lvl1->isVisible = false;
    trigger6lvl1->tag = DEFAULT;
    trigger6lvl1->OnUpdate = &TriggerUpdate;
    sprintf(trigger6lvl1->name, "You enter a massive room. It feels like an empty church.\r\nIf you could scream, echo and reverb would wash over you.");

    //DOORS AND KEYS
        //key 1 for door 1 in level 1
    key1lvl1 = ADD_ENTITY();
    key1lvl1->isFile = true;
    key1lvl1->isJob = true;
    key1lvl1->isVisible = true;
    key1lvl1->sprite = 'K';
    key1lvl1->position.x = 18;
    key1lvl1->position.y = 17;
    key1lvl1->tag = PICKUP;
    key1lvl1->level = 1;
    key1lvl1->OnUse = &UseKey;
    key1lvl1->useParam = key1lvl1;
    sprintf(key1lvl1->name, "1.key");
        //first door the player shall open
    door1lvl1 = ADD_ENTITY();
    door1lvl1->isFile = false;
    door1lvl1->isJob = true;
    door1lvl1->sprite = '%';
    door1lvl1->level = 1;
    door1lvl1->position.x = 29;
    door1lvl1->position.y = 19;
    door1lvl1->isVisible = true;
    door1lvl1->tag = DOOR;
    sprintf(door1lvl1->name, "1.door");

        //key 2 to the south section
    key2lvl1 = ADD_ENTITY();
    key2lvl1->isFile = true;
    key2lvl1->isJob = true;
    key2lvl1->isVisible = true;
    key2lvl1->sprite = 'K';
    key2lvl1->position.x = 34;
    key2lvl1->position.y = 28;
    key2lvl1->tag = PICKUP;
    key2lvl1->level = 1;
    key2lvl1->OnUse = &UseKey;
    key2lvl1->useParam = key2lvl1;
    sprintf(key2lvl1->name, "2.key");

        //door 2 south level 1
    door2lvl1 = ADD_ENTITY();
    door2lvl1->isFile = false;
    door2lvl1->isJob = true;
    door2lvl1->sprite = '%';
    door2lvl1->level = 1;
    door2lvl1->position.x = 22;
    door2lvl1->position.y = 9;
    door2lvl1->isVisible = true;
    door2lvl1->tag = DOOR;
    sprintf(door2lvl1->name, "2.door");

        //key 4, inside the room to the left of the 3 doors room
    key4lvl1 = ADD_ENTITY();
    key4lvl1->isFile = true;
    key4lvl1->isJob = true;
    key4lvl1->isVisible = true;
    key4lvl1->sprite = 'K';
    key4lvl1->position.x = 29;
    key4lvl1->position.y = 12;
    key4lvl1->tag = PICKUP;
    key4lvl1->level = 1;
    key4lvl1->OnUse = &UseKey;
    key4lvl1->useParam = key4lvl1;
    sprintf(key4lvl1->name, "4.key");

        //door 4 to go up to then go to start going to tux level
    door4lvl1 = ADD_ENTITY();
    door4lvl1->isFile = false;
    door4lvl1->isJob = true;
    door4lvl1->sprite = '%';
    door4lvl1->level = 1;
    door4lvl1->position.x = 14;
    door4lvl1->position.y = 9;
    door4lvl1->isVisible = true;
    door4lvl1->tag = DOOR;
    sprintf(door4lvl1->name, "4.door");

        //Door to secret room at the end of hallway

    key5lvl1 = ADD_ENTITY();
    key5lvl1->isFile = true;
    key5lvl1->isJob = true;
    key5lvl1->isVisible = true;
    key5lvl1->sprite = 'K';
    key5lvl1->position.x = 5;
    key5lvl1->position.y = 5;
    key5lvl1->tag = PICKUP;
    key5lvl1->level = 1;
    key5lvl1->OnUse = &UseKey;
    key5lvl1->useParam =key5lvl1;
    sprintf(key5lvl1->name, "5.key");

    door5lvl1 = ADD_ENTITY();
    door5lvl1->isFile = false;
    door5lvl1->isJob = true;
    door5lvl1->sprite = '%';
    door5lvl1->level = 1;
    door5lvl1->position.x = 55;
    door5lvl1->position.y = 21;
    door5lvl1->isVisible = true;
    door5lvl1->tag = DOOR;
    sprintf(door5lvl1->name, "5.door");

    //another door 5 so the player can open it with key 5 again
    //cuz If the player finds an easter egg too soon into the game it cang et confusing
    door52lvl1 = ADD_ENTITY();
    door52lvl1->isFile = false;
    door52lvl1->isJob = true;
    door52lvl1->sprite = '%';
    door52lvl1->level = 1;
    door52lvl1->position.x = 54;
    door52lvl1->position.y = 19;
    door52lvl1->isVisible = true;
    door52lvl1->tag = DOOR;
    sprintf(door52lvl1->name, "5.door");

        //FINAL DOORS
        //door 1 "Tux"
    key0lvl1 = ADD_ENTITY();
    key0lvl1->isFile = true;
    key0lvl1->isJob = true;
    key0lvl1->isVisible = true;
    key0lvl1->sprite = 'K';
    key0lvl1->position.x = 34;
    key0lvl1->position.y = 11;
    key0lvl1->tag = PICKUP;
    key0lvl1->level = 4;
    key0lvl1->OnUse = &UseKey;
    key0lvl1->useParam = key0lvl1;
    sprintf(key0lvl1->name, "0.key");

    door0lvl1 = ADD_ENTITY();
    door0lvl1->isFile = false;
    door0lvl1->isJob = true;
    door0lvl1->sprite = '%';
    door0lvl1->level = 1;
    door0lvl1->position.x = 49;
    door0lvl1->position.y = 12;
    door0lvl1->isVisible = true;
    door0lvl1->tag = DOOR;
    sprintf(door0lvl1->name, "0.door");

        //door 2 "Torvalds"
    door9lvl1 = ADD_ENTITY();
    door9lvl1->isFile = false;
    door9lvl1->isJob = true;
    door9lvl1->sprite = '%';
    door9lvl1->level = 1;
    door9lvl1->position.x = 49;
    door9lvl1->position.y = 8;
    door9lvl1->isVisible = true;
    door9lvl1->tag = DOOR;
    sprintf(door9lvl1->name, "9.door");
        //door 3 "1991"

    key8lvl1 = ADD_ENTITY();
    key8lvl1->isFile = true;
    key8lvl1->isJob = true;
    key8lvl1->isVisible = true;
    key8lvl1->sprite = 'K';
    key8lvl1->position.x = 7;
    key8lvl1->position.y = 29;
    key8lvl1->tag = PICKUP;
    key8lvl1->level = 1;
    key8lvl1->OnUse = &UseKey;
    key8lvl1->useParam = key8lvl1;
    sprintf(key8lvl1->name, "8.key");

    
    door8lvl1 = ADD_ENTITY();
    door8lvl1->isFile = false;
    door8lvl1->isJob = true;
    door8lvl1->sprite = '%';
    door8lvl1->level = 1;
    door8lvl1->position.x = 49;
    door8lvl1->position.y = 4;
    door8lvl1->isVisible = true;
    door8lvl1->tag = DOOR;
    sprintf(door8lvl1->name, "8.door");
    
    
    //scrolls and glyphs section for level 1
        //awakening scroll
    scroll1lvl1 = ADD_ENTITY();
    scroll1lvl1->isFile = false;
    scroll1lvl1->isJob = false;
    scroll1lvl1->isVisible = true;
    scroll1lvl1->level = 1;
    scroll1lvl1->position.x = 32;
    scroll1lvl1->position.y = 18;
    scroll1lvl1->sprite = '@';
    scroll1lvl1->tag = PICKUP;
    scroll1lvl1->OnUse = &WriteToTerminalOutput;
    scroll1lvl1->useParam = &scrollText1;
    sprintf(scroll1lvl1->name, "awakening.scroll");

        //linux scroll
    scroll2lvl1 = ADD_ENTITY();
    scroll2lvl1->isFile = false;
    scroll2lvl1->isJob = false;
    scroll2lvl1->isVisible = true;
    scroll2lvl1->level = 1;
    scroll2lvl1->position.x = 25;
    scroll2lvl1->position.y = 25;
    scroll2lvl1->sprite = '@';
    scroll2lvl1->tag = PICKUP;
    scroll2lvl1->OnUse = &WriteToTerminalOutput;
    scroll2lvl1->useParam = &scrollText2;
    sprintf(scroll2lvl1->name, "linux.scroll");

        //scroll for player to find sus room
    scroll3lvl1 = ADD_ENTITY();
    scroll3lvl1->isFile = false;
    scroll3lvl1->isJob = false;
    scroll3lvl1->isVisible = true;
    scroll3lvl1->level = 1;
    scroll3lvl1->position.x = 56;
    scroll3lvl1->position.y = 22;
    scroll3lvl1->sprite = '@';
    scroll3lvl1->tag = PICKUP;
    scroll3lvl1->OnUse = &WriteToTerminalOutput;
    scroll3lvl1->useParam = &scrollText3;
    sprintf(scroll3lvl1->name, "secretlevel.scroll");

        //scroll corner left go to tux
    scroll4lvl1 = ADD_ENTITY();
    scroll4lvl1->isFile = false;
    scroll4lvl1->isJob = false;
    scroll4lvl1->isVisible = true;
    scroll4lvl1->level = 1;
    scroll4lvl1->position.x = 1;
    scroll4lvl1->position.y = 20;
    scroll4lvl1->sprite = '@';
    scroll4lvl1->tag = PICKUP;
    scroll4lvl1->OnUse = &WriteToTerminalOutput;
    scroll4lvl1->useParam = &scrollText4;
    sprintf(scroll4lvl1->name, "FirstEncounter.scroll");

    //talking to tux
    scroll5lvl1 = ADD_ENTITY();
    scroll5lvl1->isFile = false;
    scroll5lvl1->isJob = false;
    scroll5lvl1->isVisible = true;
    scroll5lvl1->level = 4;
    scroll5lvl1->position.x = 29;
    scroll5lvl1->position.y = 11;
    scroll5lvl1->sprite = '@';
    scroll5lvl1->tag = PICKUP;
    scroll5lvl1->OnUse = &WriteToTerminalOutput;
    scroll5lvl1->useParam = &scrollText5;
    sprintf(scroll5lvl1->name, "penguin.scroll");
        //glyphs
        //glyph for funny trap room warning the player
    glyph1 = ADD_ENTITY();
    glyph1->isFile = false;
    glyph1->isJob = false;
    glyph1->isVisible = true;
    glyph1->level = 1;
    glyph1->position.x = 45;
    glyph1->position.y = 27;
    glyph1->sprite = 'X';
    glyph1->tag = DEFAULT;
    glyph1->OnInteract= &AddToTerminalOutput;
    glyph1->useParam = &glyphText1;
    sprintf(glyph1->name, "glyph1.glyph");

        //room with 3 doors, explains the player a little story wise
    glyph2 = ADD_ENTITY();
    glyph2->isFile = false;
    glyph2->isJob = false;
    glyph2->isVisible = true;
    glyph2->level = 1;
    glyph2->position.x = 44;
    glyph2->position.y = 8;
    glyph2->sprite = 'X';
    glyph2->tag = DEFAULT;
    glyph2->OnInteract= &AddToTerminalOutput;
    glyph2->useParam = &glyphText2;
    sprintf(glyph2->name, "glyph2.glyph");

        //glyph warning in hallway all the way to the left
    glyph3 = ADD_ENTITY();
    glyph3->isFile = false;
    glyph3->isJob = false;
    glyph3->isVisible = true;
    glyph3->level = 1;
    glyph3->position.x = 13;
    glyph3->position.y = 10;
    glyph3->sprite = 'X';
    glyph3->tag = DEFAULT;
    glyph3->OnInteract= &AddToTerminalOutput;
    glyph3->useParam = &glyphText1;
    sprintf(glyph3->name, "glyph3.glyph");

    glyph4 = ADD_ENTITY();
    glyph4->isFile = false;
    glyph4->isJob = false;
    glyph4->isVisible = true;
    glyph4->level = 1;
    glyph4->position.x = 47;
    glyph4->position.y = 18;
    glyph4->sprite = 'X';
    glyph4->tag = DEFAULT;
    glyph4->OnInteract= &AddToTerminalOutput;
    glyph4->useParam = &glyphText4;
    sprintf(glyph4->name, "glyph4.glyph");

    //Final glyphs
    glyph0 = ADD_ENTITY();
    glyph0->isFile = false;
    glyph0->isJob = false;
    glyph0->isVisible = true;
    glyph0->level = 1;
    glyph0->position.x = 58;
    glyph0->position.y = 12;
    glyph0->sprite = 'X';
    glyph0->tag = DEFAULT;
    glyph0->OnInteract= &AddToTerminalOutput;
    glyph0->useParam = &glyphText0;
    sprintf(glyph0->name, "glyph0.glyph");

    glyph9 = ADD_ENTITY();
    glyph9->isFile = false;
    glyph9->isJob = false;
    glyph9->isVisible = true;
    glyph9->level = 1;
    glyph9->position.x = 55;
    glyph9->position.y = 9;
    glyph9->sprite = 'X';
    glyph9->tag = DEFAULT;
    glyph9->OnInteract= &AddToTerminalOutput;
    glyph9->useParam = &glyphText9;
    sprintf(glyph9->name, "glyph9.glyph");

    glyph8 = ADD_ENTITY();
    glyph8->isFile = false;
    glyph8->isJob = false;
    glyph8->isVisible = true;
    glyph8->level = 1;
    glyph8->position.x = 57;
    glyph8->position.y = 4;
    glyph8->sprite = 'X';
    glyph8->tag = DEFAULT;
    glyph8->OnInteract= &AddToTerminalOutput;
    glyph8->useParam = &glyphText8;
    sprintf(glyph8->name, "glyph8.glyph");

    glyph10 = ADD_ENTITY();
    glyph10->isFile = false;
    glyph10->isJob = false;
    glyph10->isVisible = true;
    glyph10->level = 1993;
    glyph10->position.x = 42;
    glyph10->position.y = 25;
    glyph10->sprite = 'X';
    glyph10->tag = DEFAULT;
    glyph10->OnInteract= &AddToTerminalOutput;
    glyph10->useParam = &glyphText10;
    sprintf(glyph10->name, "glyph10.glyph");

    //Chests, lanterns and traps
        //Chest1
    chest = ADD_ENTITY();
    chest->isFile = true;
    chest->isJob = false;
    chest->isVisible = true;
    chest->level = 1;
    chest->position.x = 58;
    chest->position.y = 26;
    chest->sprite = 'X';
    chest->tag = DEFAULT;
    chest->OnInteract = &OpenChest;
    sprintf(chest->name, "chest.container");

        //chest2 in room of key 3
    chest2 = ADD_ENTITY();
    chest2->isFile = true;
    chest2->isJob = false;
    chest2->isVisible = true;
    chest2->level = 1;
    chest2->position.x = 33;
    chest2->position.y = 10;
    chest2->sprite = 'X';
    chest2->tag = DEFAULT;
    chest2->OnInteract = &OpenChest;
    sprintf(chest2->name, "chest2.container");

    chest3 = ADD_ENTITY();
    chest3->isFile = true;
    chest3->isJob = false;
    chest3->isVisible = true;
    chest3->level = 1;
    chest3->position.x = 9;
    chest3->position.y = 7;
    chest3->sprite = 'X';
    chest3->tag = DEFAULT;
    chest3->OnInteract = &OpenChest;
    sprintf(chest3->name, "chest3.container");

    chest4 = ADD_ENTITY();
    chest4->isFile = true;
    chest4->isJob = false;
    chest4->isVisible = true;
    chest4->level = 1;
    chest4->position.x = 36;
    chest4->position.y = 16;
    chest4->sprite = 'X';
    chest4->tag = DEFAULT;
    chest4->OnInteract = &OpenChest;
    sprintf(chest4->name, "chest4.container");

        //Lantern1
    lantern1 = ADD_ENTITY();
    lantern1->isFile = true;
    lantern1->isJob = false;
    lantern1->isVisible = true;
    lantern1->level = 1;
    lantern1->position.x = 46;
    lantern1->position.y = 29;
    lantern1->sprite = '*';
    lantern1->tag = PICKUP;
    lantern1->OnUse = &UseLantern;
    sprintf(lantern1->name, "lantern1.light");

    //Lantern2
    lantern2 = ADD_ENTITY();
    lantern2->isFile = true;
    lantern2->isJob = false;
    lantern2->isVisible = true;
    lantern2->level = 1;
    lantern2->position.x = 30;
    lantern2->position.y = 3;
    lantern2->sprite = '*';
    lantern2->tag = PICKUP;
    lantern2->OnUse = &UseLantern;
    sprintf(lantern2->name, "lantern2.light");
        //Traps for trap room with key 2
    trap1 = ADD_ENTITY();
    trap1->isFile = false;
    trap1->isJob = false;
    trap1->isVisible= false;
    trap1->level = 1;
    trap1->position.x = 35;
    trap1->position.y = 28;
    trap1->sprite = 'T';
    trap1->tag = TRAP;
    trap1->OnUpdate = &TriggerTrap;
    sprintf(trap1->name, "trap1.trap");

    trap2 = ADD_ENTITY();
    trap2->isFile = false;
    trap2->isJob = false;
    trap2->isVisible= false;
    trap2->level = 1;
    trap2->position.x = 34;
    trap2->position.y = 27;
    trap2->sprite = 'T';
    trap2->tag = TRAP;
    trap2->OnUpdate = &TriggerTrap;
    sprintf(trap2->name, "trap2.trap");

    trap3 = ADD_ENTITY();
    trap3->isFile = false;
    trap3->isJob = false;
    trap3->isVisible= false;
    trap3->level = 1;
    trap3->position.x = 40;
    trap3->position.y = 25;
    trap3->sprite = 'T';
    trap3->tag = TRAP;
    trap3->OnUpdate = &TriggerTrap;
    sprintf(trap3->name, "trap3.trap");

    trap4 = ADD_ENTITY();
    trap4->isFile = false;
    trap4->isJob = false;
    trap4->isVisible= false;
    trap4->level = 1;
    trap4->position.x = 41;
    trap4->position.y = 26;
    trap4->sprite = 'T';
    trap4->tag = TRAP;
    trap4->OnUpdate = &TriggerTrap;
    sprintf(trap4->name, "trap4.trap");

    trap5 = ADD_ENTITY();
    trap5->isFile = false;
    trap5->isJob = false;
    trap5->isVisible= false;
    trap5->level = 1;
    trap5->position.x = 40;
    trap5->position.y = 24;
    trap5->sprite = 'T';
    trap5->tag = TRAP;
    trap5->OnUpdate = &TriggerTrap;
    sprintf(trap5->name, "trap5.trap");

    trap6 = ADD_ENTITY();
    trap6->isFile = false;
    trap6->isJob = false;
    trap6->isVisible= false;
    trap6->level = 1;
    trap6->position.x = 37;
    trap6->position.y = 26;
    trap6->sprite = 'T';
    trap6->tag = TRAP;
    trap6->OnUpdate = &TriggerTrap;
    sprintf(trap6->name, "trap6.trap");

    trap7 = ADD_ENTITY();
    trap7->isFile = false;
    trap7->isJob = false;
    trap7->isVisible = false;
    trap7->level = 1;
    trap7->position.x = 38;
    trap7->position.y = 29;
    trap7->sprite = 'T';
    trap7->tag = TRAP;
    trap7->OnUpdate = &TriggerTrap;
    sprintf(trap7->name, "trap7.trap");

    //Traps in hallway to the left

    trap8 = ADD_ENTITY();
    trap8->isFile = false;
    trap8->isJob = false;
    trap8->isVisible = false;
    trap8->level = 1;
    trap8->position.x = 7;
    trap8->position.y = 12;
    trap8->sprite = 'T';
    trap8->tag = TRAP;
    trap8->OnUpdate = &TriggerTrapOnce;
    sprintf(trap8->name, "trap8.trap");

    trap9 = ADD_ENTITY();
    trap9->isFile = false;
    trap9->isJob = false;
    trap9->isVisible = false;
    trap9->level = 1;
    trap9->position.x = 14;
    trap9->position.y = 12;
    trap9->sprite = 'T';
    trap9->tag = TRAP;
    trap9->OnUpdate = &TriggerTrapOnce;
    sprintf(trap9->name, "trap9.trap");

    trap10 = ADD_ENTITY();
    trap10->isFile = false;
    trap10->isJob = false;
    trap10->isVisible = false;
    trap10->level = 1;
    trap10->position.x = 38;
    trap10->position.y = 29;
    trap10->sprite = 'T';
    trap10->tag = TRAP;
    trap10->OnUpdate = &TriggerTrapOnce;
    sprintf(trap10->name, "trap10.trap");

    trap11 = ADD_ENTITY();
    trap11->isFile = false;
    trap11->isJob = false;
    trap11->isVisible = false;
    trap11->level = 1;
    trap11->position.x =4;
    trap11->position.y = 11;
    trap11->sprite = 'T';
    trap11->tag = TRAP;
    trap11->OnUpdate = &TriggerTrapOnce;
    sprintf(trap11->name, "trap11.trap");

    trap12 = ADD_ENTITY();
    trap12->isFile = false;
    trap12->isJob = false;
    trap12->isVisible = false;
    trap12->level = 1;
    trap12->position.x = 6;
    trap12->position.y = 13;
    trap12->sprite = 'T';
    trap12->tag = TRAP;
    trap12->OnUpdate = &TriggerTrapOnce;
    sprintf(trap12->name, "trap12.trap");

    //LEVEL 2

    entity2 = ADD_ENTITY();
    entity2->isFile = true;
    entity2->isJob = true;
    entity2->isVisible = true;
    entity2->level = 2;
    entity2->position.x = 10;
    entity2->position.y = 10;
    entity2->sprite = 'K';
    entity2->tag = PICKUP;
    entity2->OnUse = &UseKey;
    entity2->useParam = entity2;
    sprintf(entity2->name, "trl.key");

    entity3 = ADD_ENTITY();
    entity3->isFile = false;
    entity3->isJob = true;
    entity3->sprite = '%';
    entity3->level = 2;
    entity3->position.x = 10;
    entity3->position.y = 26;
    entity3->isVisible = true;
    entity3->tag = DOOR;
    sprintf(entity3->name, "trl.door");

    //SECRET LEVELS 
    //SECRET STUFF

    //Among us level
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

    //keys for level 2
    key1lvl2=ADD_ENTITY();
    key1lvl2->isFile = true;
    key1lvl2->isJob = true;
    key1lvl2->isVisible = true;
    key1lvl2->sprite = 'K'; 
    key1lvl2->level = 2; 
    key1lvl2->position.x = 38; 
    key1lvl2->position.y = 20; 
    key1lvl2-> tag = PICKUP; 
    key1lvl2->OnUse = &UseKey; 
    key1lvl2 -> useParam = key1lvl2; 
    sprintf(key1lvl2->name,"b.key");

    key2lvl2=ADD_ENTITY();
    key2lvl2->isFile = true;
    key2lvl2->isJob = true;
    key2lvl2->isVisible = true;
    key2lvl2->sprite = 'K'; 
    key2lvl2->level = 2; 
    key2lvl2->position.x = 9; 
    key2lvl2->position.y = 20; 
    key2lvl2-> tag = PICKUP; 
    key2lvl2->OnUse = &UseKey; 
    key2lvl2 -> useParam = key2lvl2; 
    sprintf(key2lvl2->name,"p.key");

    key3lvl2=ADD_ENTITY();
    key3lvl2->isFile = true;
    key3lvl2->isJob = true;
    key3lvl2->isVisible = true;
    key3lvl2->sprite = 'K'; 
    key3lvl2->level = 2; 
    key3lvl2->position.x = 30; 
    key3lvl2->position.y = 3; 
    key3lvl2-> tag = PICKUP; 
    key3lvl2->OnUse = &UseKey; 
    key3lvl2 -> useParam = key3lvl2; 
    sprintf(key3lvl2->name,"q.key");

    //doors for level 2
    door1lvl2=ADD_ENTITY();
    door1lvl2->isFile = false;
    door1lvl2->isJob = true;
    door1lvl2->isVisible = true;
    door1lvl2->sprite = '%';
    door1lvl2->level = 2;
    door1lvl2->position.x = 5;
    door1lvl2->position.y = 14;
    door1lvl2->tag = DOOR;
    sprintf(door1lvl2->name, "b.door");

    door2lvl2=ADD_ENTITY();
    door2lvl2->isFile = false;
    door2lvl2->isJob = true;
    door2lvl2->isVisible = true;
    door2lvl2->sprite = '%';
    door2lvl2->level = 2;
    door2lvl2->position.x = 34;
    door2lvl2->position.y = 9;
    door2lvl2->tag = DOOR;
    sprintf(door2lvl2->name, "p.door");

    //scrolls for level 2
    scroll1lvl2=ADD_ENTITY(); 
    scroll1lvl2->isFile = true; 
    scroll1lvl2->isJob = false; 
    scroll1lvl2->isVisible=true; 
    scroll1lvl2->level = 2; 
    scroll1lvl2->position.x=22; 
    scroll1lvl2->position.y=11;
    scroll1lvl2->sprite='@';
    scroll1lvl2->tag = PICKUP; 
    scroll1lvl2->OnUse = &WriteToTerminalOutput; 
    scroll1lvl2->useParam=&scroll1lvl2text;
    sprintf(scroll1lvl2->name, "scroll1lvl2.scroll");

    scroll2lvl2=ADD_ENTITY(); 
    scroll2lvl2->isFile = true; 
    scroll2lvl2->isJob = false; 
    scroll2lvl2->isVisible=true; 
    scroll2lvl2->level = 2; 
    scroll2lvl2->position.x=30; 
    scroll2lvl2->position.y=10;
    scroll2lvl2->sprite='@';
    scroll2lvl2->tag = PICKUP; 
    scroll2lvl2->OnUse = &WriteToTerminalOutput; 
    scroll2lvl2->useParam=&scroll2lvl2text;
    sprintf(scroll2lvl2->name, "scroll2lvl2.scroll");

    scroll3lvl2=ADD_ENTITY(); 
    scroll3lvl2->isFile = true; 
    scroll3lvl2->isJob = false; 
    scroll3lvl2->isVisible=true; 
    scroll3lvl2->level = 2; 
    scroll3lvl2->position.x=30; 
    scroll3lvl2->position.y=8;
    scroll3lvl2->sprite='@';
    scroll3lvl2->tag = PICKUP; 
    scroll3lvl2->OnUse = &WriteToTerminalOutput; 
    scroll3lvl2->useParam=&scroll3lvl2text;
    sprintf(scroll3lvl2->name, "scroll3lvl2.scroll");

    //glyphs for level 2
    glyph1lvl2=ADD_ENTITY(); 
    glyph1lvl2->isFile=true; 
    glyph1lvl2->isJob=true;
    glyph1lvl2->isVisible=true; 
    glyph1lvl2->level=2; 
    glyph1lvl2->position.x=9;
    glyph1lvl2->position.y=10; 
    glyph1lvl2->sprite='X';
    glyph1lvl2->tag=DEFAULT;
    glyph1lvl2->OnInteract=&AddToTerminalOutput; 
    glyph1lvl2->useParam=&glyph1lvl2text; 
    sprintf(glyph1lvl2->name,"glyph1lvl2.glyph"); 

    glyph2lvl2=ADD_ENTITY(); 
    glyph2lvl2->isFile=true; 
    glyph2lvl2->isJob=true;
    glyph2lvl2->isVisible=true; 
    glyph2lvl2->level=2; 
    glyph2lvl2->position.x=1;
    glyph2lvl2->position.y=7; 
    glyph2lvl2->sprite='X';
    glyph2lvl2->tag=DEFAULT;
    glyph2lvl2->OnInteract=&AddToTerminalOutput; 
    glyph2lvl2->useParam=&glyph2lvl2text; 
    sprintf(glyph2lvl2->name,"glyph2lvl2.glyph"); 

    glyph3lvl2=ADD_ENTITY(); 
    glyph3lvl2->isFile=true; 
    glyph3lvl2->isJob=true;
    glyph3lvl2->isVisible=true; 
    glyph3lvl2->level=2; 
    glyph3lvl2->position.x=9;
    glyph3lvl2->position.y=15; 
    glyph3lvl2->sprite='X';
    glyph3lvl2->tag=DEFAULT;
    glyph3lvl2->OnInteract=&AddToTerminalOutput; 
    glyph3lvl2->useParam=&glyph3lvl2text; 
    sprintf(glyph3lvl2->name,"glyph3lvl2.glyph"); 

    //trigger for level 2 
    triggerlvl2=ADD_ENTITY();
    triggerlvl2->isFile=false; 
    triggerlvl2->sprite=' ';
    triggerlvl2->level = 2; 
    triggerlvl2->position.x=5; 
    triggerlvl2->position.y=15; 
    triggerlvl2->isVisible=false; 
    triggerlvl2->tag=DEFAULT; 
    triggerlvl2->OnUpdate=&TriggerUpdate; 
    sprintf(triggerlvl2->name, "Some light in here would be nice");

    //traps for level 2
    trap1lvl2 = ADD_ENTITY(); 
    trap1lvl2-> isFile = false; 
    trap1lvl2-> isJob = false; 
    trap1lvl2-> isVisible =false; 
    trap1lvl2-> level = 2; 
    trap1lvl2-> position.x=8; 
    trap1lvl2-> position.y=10;
    trap1lvl2-> sprite = 'T';
    trap1lvl2-> tag = TRAP; 
    trap1lvl2-> OnUpdate = &TriggerTrap;
    sprintf(trap1lvl2-> name, ".trap1lvl2.trap");

    trap2lvl2 = ADD_ENTITY(); 
    trap2lvl2-> isFile = false; 
    trap2lvl2-> isJob = false; 
    trap2lvl2-> isVisible =false; 
    trap2lvl2-> level = 2; 
    trap2lvl2-> position.x=8; 
    trap2lvl2-> position.y=16;
    trap2lvl2-> sprite = 'T';
    trap2lvl2-> tag = TRAP; 
    trap2lvl2-> OnUpdate = &TriggerTrap;
    sprintf(trap2lvl2-> name, ".trap2lvl2.trap"); 

    trap3lvl2 = ADD_ENTITY(); 
    trap3lvl2-> isFile = false; 
    trap3lvl2-> isJob = false; 
    trap3lvl2-> isVisible =false; 
    trap3lvl2-> level = 2; 
    trap3lvl2-> position.x=9; 
    trap3lvl2-> position.y=16;
    trap3lvl2-> sprite = 'T';
    trap3lvl2-> tag = TRAP; 
    trap3lvl2-> OnUpdate = &TriggerTrap;
    sprintf(trap3lvl2-> name, ".trap3lvl2.trap"); 

    trap4lvl2 = ADD_ENTITY(); 
    trap4lvl2-> isFile = false; 
    trap4lvl2-> isJob = false; 
    trap4lvl2-> isVisible =false; 
    trap4lvl2-> level = 2; 
    trap4lvl2-> position.x=37; 
    trap4lvl2-> position.y=8;
    trap4lvl2-> sprite = 'T';
    trap4lvl2-> tag = TRAP; 
    trap4lvl2-> OnUpdate = &TriggerTrap;
    sprintf(trap4lvl2-> name, ".trap4lvl2.trap"); 

    //chests for level 2
    chest1lvl2=ADD_ENTITY(); 
    chest1lvl2-> isFile = true; 
    chest1lvl2-> isJob = false; 
    chest1lvl2-> isVisible = true; 
    chest1lvl2-> level=2; 
    chest1lvl2-> position.x=12; 
    chest1lvl2-> position.y=3;
    chest1lvl2-> sprite = 'X'; 
    chest1lvl2-> tag = DEFAULT; 
    chest1lvl2-> OnInteract = &OpenChest; 
    sprintf( chest1lvl2-> name, "chest1lvl2.container"); 

    chest2lvl2=ADD_ENTITY(); 
    chest2lvl2-> isFile = true; 
    chest2lvl2-> isJob = false; 
    chest2lvl2-> isVisible = true; 
    chest2lvl2-> level=2; 
    chest2lvl2-> position.x=27; 
    chest2lvl2-> position.y=3;
    chest2lvl2-> sprite = 'X'; 
    chest2lvl2-> tag = DEFAULT; 
    chest2lvl2-> OnInteract = &OpenChest; 
    sprintf( chest2lvl2-> name, "chest2lvl2.container"); 

    chest3lvl2=ADD_ENTITY(); 
    chest3lvl2-> isFile = true; 
    chest3lvl2-> isJob = false; 
    chest3lvl2-> isVisible = true; 
    chest3lvl2-> level=2; 
    chest3lvl2-> position.x=38; 
    chest3lvl2-> position.y=10;
    chest3lvl2-> sprite = 'X'; 
    chest3lvl2-> tag = DEFAULT; 
    chest3lvl2-> OnInteract = &OpenChest; 
    sprintf( chest3lvl2-> name, "chest3lvl2.container");

    chest4lvl2=ADD_ENTITY(); 
    chest4lvl2-> isFile = true; 
    chest4lvl2-> isJob = false; 
    chest4lvl2-> isVisible = true; 
    chest4lvl2-> level=2; 
    chest4lvl2-> position.x=38; 
    chest4lvl2-> position.y=8;
    chest4lvl2-> sprite = 'X'; 
    chest4lvl2-> tag = DEFAULT; 
    chest4lvl2-> OnInteract = &OpenChest; 
    sprintf( chest4lvl2-> name, "chest4lvl2.container"); 

    //lantern for level 2
    lanternlvl2=ADD_ENTITY(); 
    lanternlvl2->isFile = true; 
    lanternlvl2->isJob =false; 
    lanternlvl2->isVisible=true; 
    lanternlvl2->level=2; 
    lanternlvl2->position.x = 2; 
    lanternlvl2->position.y = 4;
    lanternlvl2->sprite='*';
    lanternlvl2->tag= PICKUP; 
    lanternlvl2->OnUse=&UseLantern; 
    sprintf(lanternlvl2->name, "lanternlvl2.light");

    //keys for level 3
    key1lvl3=ADD_ENTITY();
    key1lvl3->isFile = true;
    key1lvl3->isJob = true;
    key1lvl3->isVisible = true;
    key1lvl3->sprite = 'K'; 
    key1lvl3->level = 3; 
    key1lvl3->position.x = 9; 
    key1lvl3->position.y = 13; 
    key1lvl3-> tag = PICKUP; 
    key1lvl3->OnUse = &UseKey; 
    key1lvl3 -> useParam = key1lvl3; 
    sprintf(key1lvl3->name,"d.key");

    key2lvl3=ADD_ENTITY();
    key2lvl3->isFile = true;
    key2lvl3->isJob = true;
    key2lvl3->isVisible = true;
    key2lvl3->sprite = 'K'; 
    key2lvl3->level = 3; 
    key2lvl3->position.x = 30; 
    key2lvl3->position.y = 3; 
    key2lvl3-> tag = PICKUP; 
    key2lvl3->OnUse = &UseKey; 
    key2lvl3 -> useParam = key2lvl3; 
    sprintf(key2lvl3->name,"8.key");

    //doors for level 3
    door1lvl3=ADD_ENTITY();
    door1lvl3->isFile = false;
    door1lvl3->isJob = true;
    door1lvl3->isVisible = true;
    door1lvl3->sprite = '%';
    door1lvl3->level = 3;
    door1lvl3->position.x = 19;
    door1lvl3->position.y = 9;
    door1lvl3->tag = DOOR;
    sprintf(door1lvl3->name, "q.door");

    door2lvl3=ADD_ENTITY();
    door2lvl3->isFile = false;
    door2lvl3->isJob = true;
    door2lvl3->isVisible = true;
    door2lvl3->sprite = '%';
    door2lvl3->level = 3;
    door2lvl3->position.x = 34;
    door2lvl3->position.y = 9;
    door2lvl3->tag = DOOR;
    sprintf(door2lvl3->name, "d.door");

    //scrolls for level 3
    scroll1lvl3=ADD_ENTITY(); 
    scroll1lvl3->isFile = true; 
    scroll1lvl3->isJob = false; 
    scroll1lvl3->isVisible=true; 
    scroll1lvl3->level = 3; 
    scroll1lvl3->position.x=17; 
    scroll1lvl3->position.y=12;
    scroll1lvl3->sprite='@';
    scroll1lvl3->tag = PICKUP; 
    scroll1lvl3->OnUse = &WriteToTerminalOutput; 
    scroll1lvl3->useParam=&scroll1lvl3text;
    sprintf(scroll1lvl3->name, "scroll1lvl3.scroll");

    scroll2lvl3=ADD_ENTITY(); 
    scroll2lvl3->isFile = true; 
    scroll2lvl3->isJob = false; 
    scroll2lvl3->isVisible=true; 
    scroll2lvl3->level = 3; 
    scroll2lvl3->position.x=1; 
    scroll2lvl3->position.y=3;
    scroll2lvl3->sprite='@';
    scroll2lvl3->tag = PICKUP; 
    scroll2lvl3->OnUse = &WriteToTerminalOutput; 
    scroll2lvl3->useParam=&scroll2lvl3text;
    sprintf(scroll2lvl3->name, "scroll2lvl3.scroll");

    scroll3lvl3=ADD_ENTITY(); 
    scroll3lvl3->isFile = true; 
    scroll3lvl3->isJob = false; 
    scroll3lvl3->isVisible=true; 
    scroll3lvl3->level = 3; 
    scroll3lvl3->position.x=9; 
    scroll3lvl3->position.y=20;
    scroll3lvl3->sprite='@';
    scroll3lvl3->tag = PICKUP; 
    scroll3lvl3->OnUse = &WriteToTerminalOutput; 
    scroll3lvl3->useParam=&scroll3lvl3text;
    sprintf(scroll3lvl3->name, "scroll3lvl3.scroll");

    //glyphs for level 3
    glyph1lvl3=ADD_ENTITY(); 
    glyph1lvl3->isFile=true; 
    glyph1lvl3->isJob=true;
    glyph1lvl3->isVisible=true; 
    glyph1lvl3->level = 3; 
    glyph1lvl3->position.x=30;
    glyph1lvl3->position.y=13; 
    glyph1lvl3->sprite='X';
    glyph1lvl3->tag=DEFAULT;
    glyph1lvl3->OnInteract=&AddToTerminalOutput; 
    glyph1lvl3->useParam=&glyph1lvl3text; 
    sprintf(glyph1lvl3->name,"glyph1lvl3.glyph"); 

    glyph2lvl3=ADD_ENTITY(); 
    glyph2lvl3->isFile=true; 
    glyph2lvl3->isJob=true;
    glyph2lvl3->isVisible=true; 
    glyph2lvl3->level = 3; 
    glyph2lvl3->position.x=38;
    glyph2lvl3->position.y=16; 
    glyph2lvl3->sprite='X';
    glyph2lvl3->tag=DEFAULT;
    glyph2lvl3->OnInteract=&AddToTerminalOutput; 
    glyph2lvl3->useParam=&glyph2lvl3text; 
    sprintf(glyph2lvl3->name,"glyph2lvl3.glyph"); 

    glyph3lvl3=ADD_ENTITY(); 
    glyph3lvl3->isFile=true; 
    glyph3lvl3->isJob=true;
    glyph3lvl3->isVisible=true; 
    glyph3lvl3->level = 3; 
    glyph3lvl3->position.x=30;
    glyph3lvl3->position.y=8; 
    glyph3lvl3->sprite='X';
    glyph3lvl3->tag=DEFAULT;
    glyph3lvl3->OnInteract=&AddToTerminalOutput; 
    glyph3lvl3->useParam=&glyph2lvl3text; 
    sprintf(glyph3lvl3->name,"glyph3lvl3.glyph"); 

    //trigger for level 3 
    triggerlvl3=ADD_ENTITY();
    triggerlvl3->isFile=false; 
    triggerlvl3->sprite=' ';
    triggerlvl3->level = 3; 
    triggerlvl3->position.x=5; 
    triggerlvl3->position.y=14; 
    triggerlvl3->isVisible=false; 
    triggerlvl3->tag=DEFAULT; 
    triggerlvl3->OnUpdate=&TriggerUpdate; 
    sprintf(triggerlvl3->name, "It looks like the place rotated");

    //traps for level 3
    trap1lvl3 = ADD_ENTITY(); 
    trap1lvl3-> isFile = false; 
    trap1lvl3-> isJob = false; 
    trap1lvl3-> isVisible =false; 
    trap1lvl3-> level = 3; 
    trap1lvl3-> position.x=2; 
    trap1lvl3-> position.y=15;
    trap1lvl3-> sprite = 'T';
    trap1lvl3-> tag = TRAP; 
    trap1lvl3-> OnUpdate = &TriggerTrap;
    sprintf(trap1lvl3-> name, ".trap1lvl3.trap");

    trap2lvl3 = ADD_ENTITY(); 
    trap2lvl3-> isFile = false; 
    trap2lvl3-> isJob = false; 
    trap2lvl3-> isVisible =false; 
    trap2lvl3-> level = 3; 
    trap2lvl3-> position.x=31; 
    trap2lvl3-> position.y=13;
    trap2lvl3-> sprite = 'T';
    trap2lvl3-> tag = TRAP; 
    trap2lvl3-> OnUpdate = &TriggerTrap;
    sprintf(trap2lvl3-> name, ".trap2lvl3.trap"); 

    trap3lvl3 = ADD_ENTITY(); 
    trap3lvl3-> isFile = false; 
    trap3lvl3-> isJob = false; 
    trap3lvl3-> isVisible =false; 
    trap3lvl3-> level = 3; 
    trap3lvl3-> position.x=31; 
    trap3lvl3-> position.y=7;
    trap3lvl3-> sprite = 'T';
    trap3lvl3-> tag = TRAP; 
    trap3lvl3-> OnUpdate = &TriggerTrap;
    sprintf(trap3lvl3-> name, ".trap3lvl3.trap"); 

    trap4lvl3 = ADD_ENTITY(); 
    trap4lvl3-> isFile = false; 
    trap4lvl3-> isJob = false; 
    trap4lvl3-> isVisible =false; 
    trap4lvl3-> level = 3; 
    trap4lvl3-> position.x=30; 
    trap4lvl3-> position.y=7;
    trap4lvl3-> sprite = 'T';
    trap4lvl3-> tag = TRAP; 
    trap4lvl3-> OnUpdate = &TriggerTrap;
    sprintf(trap4lvl3-> name, ".trap4lvl3.trap"); 

    //chests for level 3
    chest1lvl3=ADD_ENTITY(); 
    chest1lvl3-> isFile = true; 
    chest1lvl3-> isJob = false; 
    chest1lvl3-> isVisible = true; 
    chest1lvl3-> level = 3; 
    chest1lvl3-> position.x=1; 
    chest1lvl3-> position.y=13;
    chest1lvl3-> sprite = 'X'; 
    chest1lvl3-> tag = DEFAULT; 
    chest1lvl3-> OnInteract = &OpenChest; 
    sprintf( chest1lvl3-> name, "chest1lvl3.container"); 

    chest2lvl3=ADD_ENTITY(); 
    chest2lvl3-> isFile = true; 
    chest2lvl3-> isJob = false; 
    chest2lvl3-> isVisible = true; 
    chest2lvl3-> level = 3; 
    chest2lvl3-> position.x=1; 
    chest2lvl3-> position.y=15;
    chest2lvl3-> sprite = 'X'; 
    chest2lvl3-> tag = DEFAULT; 
    chest2lvl3-> OnInteract = &OpenChest; 
    sprintf( chest2lvl3-> name, "chest2lvl3.container"); 

    chest3lvl3=ADD_ENTITY(); 
    chest3lvl3-> isFile = true; 
    chest3lvl3-> isJob = false; 
    chest3lvl3-> isVisible = true; 
    chest3lvl3-> level = 3; 
    chest3lvl3-> position.x=12; 
    chest3lvl3-> position.y=20;
    chest3lvl3-> sprite = 'X'; 
    chest3lvl3-> tag = DEFAULT; 
    chest3lvl3-> OnInteract = &OpenChest; 
    sprintf( chest3lvl3-> name, "chest3lvl3.container");

    chest4lvl3=ADD_ENTITY(); 
    chest4lvl3-> isFile = true; 
    chest4lvl3-> isJob = false; 
    chest4lvl3-> isVisible = true; 
    chest4lvl3-> level = 3; 
    chest4lvl3-> position.x=27; 
    chest4lvl3-> position.y=20;
    chest4lvl3-> sprite = 'X'; 
    chest4lvl3-> tag = DEFAULT; 
    chest4lvl3-> OnInteract = &OpenChest; 
    sprintf( chest4lvl3-> name, "chest4lvl3.container"); 

    //lantern for level 3
    lanternlvl3=ADD_ENTITY(); 
    lanternlvl3->isFile = true; 
    lanternlvl3->isJob =false; 
    lanternlvl3->isVisible=true; 
    lanternlvl3->level = 3; 
    lanternlvl3->position.x = 37; 
    lanternlvl3->position.y = 19;
    lanternlvl3->sprite='*';
    lanternlvl3->tag= PICKUP; 
    lanternlvl3->OnUse=&UseLantern; 
    sprintf(lanternlvl3->name, "lanternlvl3.light");

    LOG_ENTITIES();
}

