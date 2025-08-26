#include "headers\unit_test.h"
#include "headers\is_zero.h"

void number_of_test_with_error(struct parametrs* ptr_input, struct test_library* ptr_answer, int res_test)
{
    int presence_of_error = comparison(ptr_input, ptr_answer, res_test);
    
    switch (presence_of_error)
    {
    case VERDICT_OK:
        printf(ANSI_COLOR_GREEN "OK" ANSI_COLOR_RESET "\n");
        break;
    
    case VERDICT_WARNING:
        warning_output(ptr_input, ptr_answer, res_test);
        break;
    }
}

int comparison(struct parametrs* ptr_input, struct test_library* ptr_answer, int res_test)
{
    if(is_zero(res_test - ptr_answer->result))
    {
        if(isnan(ptr_input->x1) && isnan(ptr_answer->x1))
        {
            if(isnan(ptr_input->x2) && isnan(ptr_answer->x2))
                return VERDICT_OK;
            else
            {
                if(!isnan(ptr_input->x2) && !isnan(ptr_answer->x2))
                {
                    if(is_zero(ptr_input->x2 - ptr_answer->x2))
                        return VERDICT_OK;

                    return VERDICT_WARNING;
                }

                return VERDICT_WARNING;
            }
        }
        else
        {
            if(!isnan(ptr_input->x1) && !isnan(ptr_answer->x1))
            {
                if(is_zero(ptr_input->x1 - ptr_answer->x1))
                {
                    if(isnan(ptr_input->x2) && isnan(ptr_answer->x2))
                        return VERDICT_OK;
                    else
                    {
                        if(!isnan(ptr_input->x2) && !isnan(ptr_answer->x2))
                        {
                            if(is_zero(ptr_input->x2 - ptr_answer->x2))
                                return VERDICT_OK;
                            
                            return VERDICT_WARNING;
                        }

                        return VERDICT_WARNING;
                    }
                }
                
                return VERDICT_WARNING;
            }

            return VERDICT_WARNING;
        }
    }
    else
        return VERDICT_WARNING;
}

void warning_output(struct parametrs* ptr_input, struct test_library* ptr_answer, int res_test)
{
    printf(ANSI_COLOR_RED "-----------------------------------------------------------------\n");
    printf("ERROR IN TEST:\n");
    printf("PROGRAM OUTPUT: x1 = %g, x2 = %g, NOR = %d\n", ptr_input->x1, ptr_input->x2, res_test);
    printf("CORRECT OUTPUT: x1 = %g, x2 = %g, NOR = %d\n-----------------------------------------------------------------" ANSI_COLOR_RESET "\n", ptr_answer->x1, ptr_answer->x2, ptr_answer->result);
}

void test()
{
    int length_input = 0;
    int length_answer = 0;
    int length_dynamic_array = 0;

    double* ptr_data_input = tests_from_txt(&length_input);

    double* ptr_data_answer = answers_from_txt(&length_answer);

    length_input /= 5;
    length_answer /= 3;

    if(length_input != length_answer)
    {
        printf(ANSI_COLOR_RED "-----------------------------------------------------------------\n");
        printf("ERROR:\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "Size of \"test_input.txt\" != size of \"test_answer.txt\"\n");
        printf("-----------------------------------------------------------------\n\n" ANSI_COLOR_RESET);
        exit(1);
    }

    length_dynamic_array = length_input;


    struct parametrs test_input[length_dynamic_array];
    struct test_library test_answer[length_dynamic_array];

    enter_test_input(ptr_data_input, test_input, length_dynamic_array);
    enter_test_answer(ptr_data_answer, test_answer, length_dynamic_array);
    

    for(int i = 0; i < length_dynamic_array; ++i)
    {
        int res_test = quadro_equation(&test_input[i]);
        number_of_test_with_error(&test_input[i], &test_answer[i], res_test);
    }

    printf("-----------------------------------------------------------------\n\n");

    free(ptr_data_input);
    free(ptr_data_answer);
}