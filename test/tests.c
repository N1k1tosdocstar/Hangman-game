#include "ctest.h"
#include <libhangman/checks.h>
CTEST(CHECKS, IS_WORD)
{
    ASSERT_EQUAL(0, isWord("123134"));
    ASSERT_EQUAL(0, isWord("d"));
    ASSERT_EQUAL(1, isWord("apple"));
}
CTEST(CHECKS, CHECK_MAX_WORDS)
{
    ASSERT_EQUAL(0, checkMaxWords(0));
    ASSERT_EQUAL(1, checkMaxWords(10));
    ASSERT_EQUAL(1, checkMaxWords(11));
    ASSERT_EQUAL(0, checkMaxWords(9));
    ASSERT_EQUAL(1, checkMaxWords(-1));
    ASSERT_EQUAL(1, checkMaxWords(20));
}
CTEST(CHECKS, CHECK_LENGTH)
{
    ASSERT_EQUAL(1, checkLength("akaljhdkjahkjahdfskjhaksdjfhalksdjfasd"));
    ASSERT_EQUAL(0, checkLength("asdf"));
    ASSERT_EQUAL(0, checkLength("asdfgasdfgasdfgasdfg"));
}
CTEST(CHECKS, CHECK_MAX_MISSES)
{
    ASSERT_EQUAL(0, checkmaxmisses(0));
    ASSERT_EQUAL(1, checkmaxmisses(10));
    ASSERT_EQUAL(1, checkmaxmisses(6));
    ASSERT_EQUAL(0, checkmaxmisses(3));
}
