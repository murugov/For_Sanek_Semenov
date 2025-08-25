#include "headers\stdout.h"

void enter(struct parametrs* ptr_stucture)
{
    assert(ptr_stucture != NULL);

    printf(ANSI_COLOR_YELLOW "");
    int checker = scanf("%lg %lg %lg", &ptr_stucture->a, &ptr_stucture->b, &ptr_stucture->c);
    printf("" ANSI_COLOR_RESET);

    while(checker != 3)
    {
        printf(ANSI_COLOR_YELLOW "");
        while(getchar() != '\n');
        printf("" ANSI_COLOR_RESET);

        printf(ANSI_COLOR_RED "Invalid input format\n" ANSI_COLOR_RESET);
        checker = scanf("%lg %lg %lg", &ptr_stucture->a, &ptr_stucture->b, &ptr_stucture->c);
    }

    printf("" ANSI_COLOR_RESET);
}

void output(int res, struct parametrs* ptr_stucture)
{
    assert(ptr_stucture != NULL);

    switch (res)
    {
        case NO_ROOTS:
            printf(ANSI_COLOR_MAGENTA "No roots\n" ANSI_COLOR_RESET);
            break;
        case ONE_ROOT:
            printf(ANSI_COLOR_MAGENTA "One root:\n");
            printf("x = %lg" ANSI_COLOR_RESET "\n", ptr_stucture->x1);
            break;
        case TWO_ROOTS:
            printf(ANSI_COLOR_MAGENTA "Two roots:\n");
            printf("x1 = %lg\n", ptr_stucture->x1);
            printf("x2 = %lg" ANSI_COLOR_RESET "\n", ptr_stucture->x2);
            break;
        case IMAGINARY_ROOTS:
            printf(ANSI_COLOR_MAGENTA "Only imaginary roots\n" ANSI_COLOR_RESET);
            break;
        case INFINITY_ROOTS:
            printf(ANSI_COLOR_MAGENTA "Infinite number of roots\n" ANSI_COLOR_RESET);
            break;
    }
}