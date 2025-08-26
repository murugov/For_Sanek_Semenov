#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "square_solver.h"
#include "colors.h"


struct test_library {
    double x1;
    double x2;
    int result;
};

void test();
int comparison(struct parametrs* ptr_input, struct test_library* ptr_answer, int res_test);
void warning_output(struct parametrs* ptr_input, struct test_library* ptr_answer, int res_test);
void number_of_test_with_error(struct parametrs* ptr_input, struct test_library* ptr_answer, int res_test);
void* tests_from_txt(int* ptr_length);
void* answers_from_txt(int* ptr_length);
void enter_test_input(double* ptr_data, struct parametrs* ptr_test_input, int length_data);
void enter_test_answer(double* ptr_data, struct test_library* ptr_test_answer, int length_data);

#endif