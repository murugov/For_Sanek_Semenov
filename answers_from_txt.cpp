#include "headers/unit_test.h"
#include "headers/my_realloc.h"
#include "headers/is_zero.h"

double* answers_from_txt(size_t* ptr_length)
{
    size_t capacity = 5;
    double* ptr_data = (double *)calloc(capacity, sizeof(double));

    if (!ptr_data) {
        exit(1);
    }

    FILE* ptr_file = fopen("tests/test_answer.txt", "r");
    if(ptr_file == NULL) {
        perror("test_answer.txt");
        exit(1);
    }

    while(NOT_END_FILE)
    {
        if (*ptr_length == capacity) 
        {
            ptr_data = my_realloc(ptr_data, ptr_length, &capacity);
            //capacity *= 2;
            //ptr_data = (double *)realloc(ptr_data, sizeof(double) * capacity);
        }

        if (fscanf(ptr_file, "%lg ", &ptr_data[*ptr_length]) == 1)
        {
            (*ptr_length)++;
        }
        else
        {
            break;
        }
    }
 
    fclose(ptr_file);
 
    return ptr_data;
}