#!/bin/bash
echo 'Compiling game...'
rm LARK_GAME.out 2>/dev/null
rm core.* 2>/dev/null
#gnu prog        Player library        Engine library  math      output       errors
gcc main.c LARK_Libraries/engine_man.c LARK_Libraries/Player.c MikeEngine/Engine.c -lm -o LARK_GAME.out 2>errors.log

ls LARK_GAME.out 2>/dev/null 1>/dev/null && echo 'Game Compiled Successfuly' && rm errors.log 2>/dev/null && chmod 744 LARK_GAME.out
ls LARK_GAME.out 2>/dev/null 1>/dev/null || echo 'ERROR! Game did not compile! Check [errors.log]'