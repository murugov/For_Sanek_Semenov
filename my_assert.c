#include <stdio.h>
#include <stdlib.h>
#include "headers/colors.h"
#include "headers/my_assert.h"

void my_assert(void* ptr/*const name_file, const line_of_file*/)
{
    if(ptr == NULL)
    {
        printf(ANSI_COLOR_RED"Assert failled: file, line:\n" ANSI_COLOR_RESET/*, name_file, line_of_file*/);
        exit(1);
    }
}