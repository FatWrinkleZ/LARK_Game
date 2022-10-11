#!/bin/bash
echo 'Compiling game...'
rm LARK_GAME.out 2>/dev/null
gcc main.c MikeEngine/Engine.c -lm -o LARK_GAME.out 2>errors.log
ls LARK_GAME.out 2>/dev/null 1>/dev/null && echo 'Game Compiled Successfuly' && rm errors.log 2>/dev/null
ls LARK_GAME.out 2>/dev/null 1>/dev/null || echo 'ERROR! Game did not compile! Check [errors.log]'