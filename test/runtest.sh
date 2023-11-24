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

tests=("first_test.c" "string_parse_test.c string_parse2_test.c" "httpcommand_test.c" "http_response_test.c" "rules_test.c" "rules_valid_request_test.c")
class=("" "../src/http/http.c" "../src/http/httpcommand.c ../src/http/http.c" "../src/http/http_response.c" "../src/http/rules.c" "../src/http/rules.c ../src/config/config.c ../src/utils/string/string.c")
label=("Sample Test" "Parse HTTP string test" "Parse HTTP message" "Parse HTTP response" "Basic Rules" "Rules Request Checking")


for (( i=0; i<=${#tests[@]}-1; i++ ))
do  
    ii=$((i+1))
    echo ""
    echo -e "${BIRed}=== (${IGreen}${ii}${BIRed}) ${label[$i]} === [ ${BICyan} ${tests[$i]} ${BIRed} ] ${NC} "
    gcc -o test ${tests[$i]} ${class[$i]} ${EXTRA_FLAGS} -lcriterion
    ./test
    echo -e "${BIRed}===================================================================${NC} "
    echo ""
done

rm test