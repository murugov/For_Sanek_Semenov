#include "headers\is_zero.h"
#include "headers\square_solver.h"

double discriminat(struct parametrs* ptr_stucture)
{
    assert(ptr_stucture != NULL);


    double D = ptr_stucture->b * ptr_stucture->b - 4 * ptr_stucture->a * ptr_stucture->c;
    return D;
}

int quadro_equation(struct parametrs* ptr_stucture)
{
    assert(ptr_stucture != NULL);

    if(is_zero(ptr_stucture->a)) 
    {
        if(is_zero(ptr_stucture->b)) 
            return (is_zero(ptr_stucture->c)) ? INFINITY_ROOTS: NO_ROOTS;
        else {
            ptr_stucture->x1 = -ptr_stucture->c/ptr_stucture->b;
            return ONE_ROOT;
        }
    }

    double D = discriminat(ptr_stucture);

    if(is_zero(D))
    {
        if(is_zero(ptr_stucture->b))
           ptr_stucture->x1 = 0;
        else
            ptr_stucture->x1 = -ptr_stucture->b / (2 * ptr_stucture->a);
        return ONE_ROOT;
    }
    else if(D < 0)
        return IMAGINARY_ROOTS;
    else {
        double x1 = (-ptr_stucture->b + sqrt(D)) / (2 * ptr_stucture->a);
        double x2 = (-ptr_stucture->b - sqrt(D)) / (2 * ptr_stucture->a);

        ptr_stucture->x1 = (x1 > x2) ? x1: x2;
        ptr_stucture->x2 = (x1 < x2) ? x1: x2;

        return TWO_ROOTS;
    }

}