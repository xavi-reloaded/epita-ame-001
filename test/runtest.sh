#!/bin/bash

unameOut="$(uname -s)"
case "${unameOut}" in
    Darwin*)    EXTRA_FLAGS="-I/opt/homebrew/include -L/opt/homebrew/lib";;
    *)          EXTRA_FLAGS=""
esac


gcc -o test first_test.c ${EXTRA_FLAGS} -lcriterion
./test

gcc -o test string_parse_test.c ../src/http/http.c ${EXTRA_FLAGS} -lcriterion
./test



