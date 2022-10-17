#include "engine_man.h"

char man_ls[100] = "Use ls to list all the directories (unlike actual bash ls, this cannot be paired with arguments)";
char man[64] = "Type man <cmd> (cmd can be 'ls', 'cat', 'jobs', 'kill', 'echo'";
char man_cat[64] = "Use cat to express contents of a file";
char man_echo[64] = "Usage : echo <str>";
char man_jobs[64] = "Use jobs to output all the current jobs";
char man_kill[64] = "Usage : kill <PID> to kill a job";
char man_cd[64] = "Usage : cd <directory>";