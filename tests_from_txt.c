#include "headers\unit_test.h"

// void* my_realloc(double* ptr_data, int* ptr_length, int* ptr_capacity)
// {
//     *ptr_capacity = *ptr_capacity * 2;
//     double* ptr_list = (double *)calloc(*ptr_capacity, sizeof(double));
//     if(ptr_list == NULL)
//         return ptr_data;
        
//     for(int i = 0;i < *ptr_length; ++i)
//         ptr_list[i] = ptr_data[i];
        
//         free(ptr_data);
//         ptr_data = ptr_list;
        
//     return ptr_data;
// }

void* tests_from_txt()
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
 
    return ptr_data;
}