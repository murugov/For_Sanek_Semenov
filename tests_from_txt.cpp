#include "headers/unit_test.h"

void* tests_from_txt(size_t* ptr_length)
{
    FILE* ptr_file = fopen("tests/tests.txt", "r");
    if(ptr_file == NULL)
    {
        perror("test_input.txt");
        exit(1);
    }

    char c = fgetc(ptr_file);

    while (c != EOF) {
        if (c == '\n') {
            (*ptr_length)++;
        }
        c = fgetc(ptr_file);
    }

    fseek(ptr_file, 0, SEEK_SET);

    (*ptr_length)++;

    struct parametrs* ptr_test = (struct parametrs*)calloc(*ptr_length, sizeof(struct parametrs));

    if (ptr_test == NULL)
    {
        perror("ptr_data");
        exit(1);
    }

    size_t i = 0;

    while(fscanf(ptr_file, "%lg %lg %lg %lg %lg %lg %lg %lg ", &ptr_test[i].a, &ptr_test[i].b, &ptr_test[i].c,
            &ptr_test[i].x1, &ptr_test[i].x2, &ptr_test[i].ans_x1, &ptr_test[i].ans_x2, &ptr_test[i].result) == 8 && i < *ptr_length)
            i++;
     
    fclose(ptr_file);
 
    return ptr_test;
}