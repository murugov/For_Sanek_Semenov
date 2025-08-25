#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "square_solver.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"


struct test_library {
    double x1;
    double x2;
    int result;
};

void test();
int comparison(struct parametrs* ptr_input, struct test_library* ptr_answer, int res_test);
void warning_output(struct parametrs* ptr_input, struct test_library* ptr_answer, int res_test);
void number_of_test_with_error(struct parametrs* ptr_input, struct test_library* ptr_answer, int res_test);
void* tests_from_txt();
void* answers_from_txt();
void enter_test_input(double* ptr_data, struct parametrs* ptr_test_input, int length_data);
void enter_test_answer(double* ptr_data, struct test_library* ptr_test_answer, int length_data);
int length_dynamic_array();

#endif