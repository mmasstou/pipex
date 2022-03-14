#!/bin/sh
#Author mohamed MASSTOUR
#42login : mmasstou

_End="\033[0m"
C_DARKVIOLET="\033[1;5;1;36m"
_BLACK="\033[38;5;16m"
_RED="\033[38;5;42m"
_GREEN="\033[38;5;32m"
_BLUE="\033[38;5;34m"
_DARK_GRY="\033[38;5;90m"




echo "                                                                        ${_RED} Login : mmasstou ${_End}"
echo "     ${C_DARKVIOLET}                          ███▄ ▄███▓ ███▄ ▄███▓ ▄▄▄        ██████   ██████ ▄▄▄█████▓ ▒█████   █    ██    "
echo "                              ▓██▒▀█▀ ██▒▓██▒▀█▀ ██▒▒████▄    ▒██    ▒ ▒██    ▒ ▓  ██▒ ▓▒▒██▒  ██▒ ██  ▓██▒   "
echo "                              ▓██    ▓██░▓██    ▓██░▒██  ▀█▄  ░ ▓██▄   ░ ▓██▄   ▒ ▓██░ ▒░▒██░  ██▒▓██  ▒██░   "
echo "                              ▒██    ▒██ ▒██    ▒██ ░██▄▄▄▄██   ▒   ██▒  ▒   ██▒░ ▓██▓ ░ ▒██   ██░▓▓█  ░██░   "
echo "                              ▒██▒   ░██▒▒██▒   ░██▒ ▓█   ▓██▒▒██████▒▒▒██████▒▒  ▒██▒ ░ ░ ████▓▒░▒▒█████▓    "
echo "                             ░ ▒░   ░  ░░ ▒░   ░  ░ ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░▒ ▒▓▒ ▒ ░  ▒ ░░   ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    "
echo "                             ░  ░      ░░  ░      ░  ▒   ▒▒ ░░ ░▒  ░ ░░ ░▒  ░ ░    ░      ░ ▒ ▒░ ░░▒░ ░ ░    "
echo "                             ░      ░   ░      ░     ░   ▒   ░  ░  ░  ░  ░  ░    ░      ░ ░ ░ ▒   ░░░ ░ ░    "
echo "                                    ░          ░         ░  ░      ░        ░               ░ ░     ░        "
echo "                                                                            mmasstou@student.1337.ma         "

echo "${_End}"
echo "${_BLACK}   +> Cleaning           ${_End} 1"
echo "${_BLACK}   +> create Programe    ${_End} 2"
echo "${_BLACK}   +> Test               ${_End} 3"
printf "\033[1;5;1;36m   +> ${_End}"
        read q
if [ $q == 1 ] ;then 
    rm -rf a.*  pipex .DS_Store outfile
    make fclean
    echo "${_BLACK}   +> Cleaning ${_End}${_RED} [Done] ${_End}"
elif [ $q == 2 ] ;then
    make bonus  -C libft/
    echo "${_BLACK}   +> libft ${_End}${_RED} [Done] ${_End}"
    make 
elif [ $q == 3 ] ;then
    echo './pipex infile "cat" "wc -l" outfile'
    ./pipex infile "cat" "wc -l" outfile
    echo './pipex infile "" "wc -l" outfile'
    ./pipex infile "" "wc -l" outfile
    echo './pipex ls "cat" "wc -l" outfile'
    ./pipex ls "cat" "wc -l" outfile
    exit 0
else 
    echo "   +> chose one of option 1/2 -> Cleaning/Test"
    exit 0
fi
