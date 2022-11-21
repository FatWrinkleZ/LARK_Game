#!/bin/bash
username=$(whoami)
echo "Welcome $username, to the LARK Game"
echo "Press 'enter' to start the game"
read
tput smcup

./.compile_game.sh && ./.LARK_GAME.out
tput rmcup
