#include "headers\unit_test.h"

int length_dynamic_array()
{
    int capacity = 5;
    int length = 0;
    double* ptr_data = (double *)calloc(capacity, sizeof(double));
    if (!ptr_data) {
        exit(1);
    }

    FILE* ptr_file = fopen("tests/test_input.txt", "r");
    if(ptr_file == NULL) {
        perror("test_input.txt");
        exit(1);
    }

    while(NOT_END_FILE)
    {
        if (length == capacity) 
        {
            capacity *= 2;
            ptr_data = (double *)realloc(ptr_data, sizeof(double) * capacity);
        }


        if (fscanf(ptr_file, "%lg ", &ptr_data[length]) == 1)
        {
            length++;
        }
        else
        {
            break;
        }
    }
 
    fclose(ptr_file);

    return length;
}