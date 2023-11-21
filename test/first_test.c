#include <criterion/criterion.h>

Test(tester, passing) 
{
    cr_assert(0);
}




Test(tester, fail) 
{
    cr_assert(1);
}