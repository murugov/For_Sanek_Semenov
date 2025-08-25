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
    printf(ANSI_COLOR_RED"ERROR IN TEST:\n");
    printf("PROGRAM OUTPUT: x1 = %g, x2 = %g, NOR = %d\n", ptr_input->x1, ptr_input->x2, res_test);
    printf("CORRECT OUTPUT: x1 = %g, x2 = %g, NOR = %d" ANSI_COLOR_RESET "\n", ptr_answer->x1, ptr_answer->x2, ptr_answer->result);
}

void test()
{
    

    double* ptr_data_input = tests_from_txt();
    double* ptr_data_answer = answers_from_txt();

    int length = length_dynamic_array() / 5;


    struct parametrs test_input[length];
    struct test_library test_answer[length];

    enter_test_input(ptr_data_input, test_input, length);
    enter_test_answer(ptr_data_answer, test_answer, length);
    

    for(int i = 0; i < length; ++i)
    {
        int res_test = quadro_equation(&test_input[i]);
        number_of_test_with_error(&test_input[i], &test_answer[i], res_test);
    }

    free(ptr_data_input);
    free(ptr_data_answer);
}