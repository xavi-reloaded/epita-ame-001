#!/bin/bash

NC='\033[0m' # No Color
IGreen='\033[0;92m'
BICyan='\033[1;96m' 
BIRed='\033[1;91m'

unameOut="$(uname -s)"
case "${unameOut}" in
    Darwin*)    EXTRA_FLAGS="-I/opt/homebrew/include -L/opt/homebrew/lib";;
    *)          EXTRA_FLAGS=""
esac

tests=("first_test.c"  "string_parse_test.c")
class=(""  "../src/http/http.c")
label=("Sample Test"  "Parse HTTP string test")


for (( i=0; i<=${#tests[@]}-1; i++ ))
do  
    ii=$((i+1))
    echo ""
    echo -e "${BIRed}=== ${label[@]:i:ii} === [ ${BICyan} ${tests[@]:i:ii} ${BIRed} ] ${NC} "
    gcc -o test ${tests[@]:i:ii} ${class[@]:i:ii} ${EXTRA_FLAGS} -lcriterion
    ./test
    echo -e "${BIRed}===================================================================${NC} "
    echo ""
done

