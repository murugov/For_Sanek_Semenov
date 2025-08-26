#ifndef STRUCT_PARAMETRS_H
#define STRUCT_PARAMETRS_H

enum {INFINITY_ROOTS = -1, NO_ROOTS, ONE_ROOT, TWO_ROOTS, IMAGINARY_ROOTS, VERDICT_OK = 0, VERDICT_WARNING, NOT_END_FILE = 1};

struct parametrs {
    double a;
    double b;
    double c;
    double x1;
    double x2;
};

#endif