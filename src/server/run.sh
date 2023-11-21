gcc -v -std=c99 -Werror -Wall -Wextra -Wvla -pedantic server.c main.c -l../config/libconfig.a

./a.out 127.0.0.1 8002
