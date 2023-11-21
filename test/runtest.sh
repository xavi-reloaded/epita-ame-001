set -i
unameOut="$(uname -s)"
case "${unameOut}" in
    Darwin*)    EXTRA_FLAGS="-I/opt/homebrew/include -L/opt/homebrew/lib";;
    *)          EXTRA_FLAGS=""
esac

gcc -o test first_test.c  ${EXTRA_FLAGS} -lcriterion
./test