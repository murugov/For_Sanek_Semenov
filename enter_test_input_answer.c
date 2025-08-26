#include "headers/unit_test.h"

void enter_test_input(double* ptr_data_input, struct parametrs* ptr_test_input, size_t length_data)
{
    for(size_t i = 0; i < length_data; ++i)
    {
        ptr_test_input[i].a = ptr_data_input[i * 5];
        ptr_test_input[i].b = ptr_data_input[i * 5 + 1];
        ptr_test_input[i].c = ptr_data_input[i * 5 + 2];
        ptr_test_input[i].x1 = ptr_data_input[i * 5 + 3];
        ptr_test_input[i].x2 = ptr_data_input[i * 5 + 4];
    }
}

void enter_test_answer(double* ptr_data_answer, struct test_library* ptr_test_answer, size_t length_data)
{
    for(size_t i = 0; i < length_data; ++i)
    {
        ptr_test_answer[i].x1 = ptr_data_answer[i * 3];
        ptr_test_answer[i].x2 = ptr_data_answer[i * 3 + 1];
        ptr_test_answer[i].result = ptr_data_answer[i * 3 + 2];
    }
}