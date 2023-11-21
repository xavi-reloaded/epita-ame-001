gcc -std=c99 -Werror -Wall -Wextra -Wvla -pedantic httpcommand.c xavi.c -o httpcommand

./httpcommand "${1} ${2}"
