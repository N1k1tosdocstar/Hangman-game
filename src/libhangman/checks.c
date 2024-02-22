#include "checks.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int checkLength(const char* str1)
{
    if (strlen(str1) - 1 > MAX_LENGTH)
        return true;

    return false;
}
int isWord(const char* str1)
{
    if (strlen(str1) == 1) {
        return false;
    }
    for (int i = 0; i < strlen(str1); i++) {
        if (str1[i] < (int)'a' || str1[i] > (int)'z')
            return false;
    }
    return true;
}
int checkMaxWords(int num)
{
    if (num >= MAX_WORDS || num < 0) {
        return true;
    }
    return false;
}
int checkmaxmisses(int num)
{
    if (num >= MAX_MISSES || num < 0) {
        return true;
    }
    return false;
}