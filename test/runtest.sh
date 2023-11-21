set -i
gcc -o test first_test.c  -I/opt/homebrew/include -L/opt/homebrew/lib -lcriterion
./test