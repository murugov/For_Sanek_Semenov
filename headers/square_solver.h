#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

enum {INFINITY_ROOTS = -1, NO_ROOTS, ONE_ROOT, TWO_ROOTS, IMAGINARY_ROOTS, VERDICT_OK = 0, VERDICT_WARNING, NOT_END_FILE = 1};

struct parametrs {
    double a;
    double b;
    double c;
    double x1;
    double x2;
};

double discriminat(struct parametrs* library);
int quadro_equation(struct parametrs* library);

#endif