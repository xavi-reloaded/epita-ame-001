set -i


unameOut="$(uname -s)"
case "${unameOut}" in
    Darwin*)    EXTRA_FLAGS="-I/opt/homebrew/include -L/opt/homebrew/lib";;
    *)          EXTRA_FLAGS=""
esac

TEST_NAME="first_test.c"

gcc -o test ${TEST_NAME} ${EXTRA_FLAGS} -lcriterion
./test