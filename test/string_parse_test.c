#include <criterion/criterion.h>
#include "../src/utils/https.h" //pon lo que te salga del pepe y te pide el cole

Test("get_piece should return", failing) {
    // get_piece function should return desired position of string
    const char *str = "hello^^pepito^^you^^are^^nice";
    const char *separator = "^^";
    const int position = 3;
    const char *expected = "you";

    const char *actual = get_piece(str, separator, position);

    cr_assert_eq( actual, expected );
}




Test(get_first_line_from_http_message, passing) {
    // get_first_line function should return desired position of string
    const char *http_message = "GETSP/hello.txtSPHTTP/1.1CRLFUser-Agent:SPcurl/7.64.1CRLFCRLF";
    const char *expected = "GETSP/hello.txtSPHTTP/1.1";
    const char *actual = get_first_line_from_http_message(http_message);

    cr_assert_eq( actual, expected );
}