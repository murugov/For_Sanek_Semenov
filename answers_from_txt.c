#include "headers\unit_test.h"

// //fseek

// +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---
// |   |33 | 2 | 1 | 0 | 0 | 2 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |   |   |   |   |   |   |   |   |  
// +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---
//     \__/ \_____________/ \_____________________________/                                   
//      c    i               l                                                                 
//     \__________________________________________________/                                    
//      st                                                                                     
//                                                                                             
// +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---
// |   |33 | ? | ? | ? | ? | ? | ? | ? | 2 | 1 | ? | ? | ? | ? | ? | ? | 2 | 1 | ? | ? | ? |  
// +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---
//     \______________________________/ \_____________________________/ \___________________....
//      c                                i                               l                     
//     \____________________________________________________________________________________....
//      st                                                                                     


// struct st
//     {
//     char c; = '!'
//     int  i; = 258 = 256*1 + 2
//     long long l; = 258
//     };

// char* pc = &st.c;
// pc++;

// fseek(my_file)

void* answers_from_txt()
{
    int capacity = 5;
    int length = 0;
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
        if (length == capacity) 
        {
            capacity *= 2;
            ptr_data = (double *)realloc(ptr_data, sizeof(double) * capacity);
        }


        if (fscanf(ptr_file, "%lg ", ptr_data + length) == 1)
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