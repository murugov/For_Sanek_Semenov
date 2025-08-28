#include "headers/unit_test.h"
#include "headers/stdout.h"
#include "headers/square_solver.h"

int main(void)
{
    printf("\n");
    printf("-----------------------------------------------------------------\n");
    printf(ANSI_COLOR_BLUE "###    Enter 't' for tester mode and 'u' for user mode    ###\n" ANSI_COLOR_RESET);
    
    int mode = 0;

    while (VERDICT_WARNING)
     {
        printf(ANSI_COLOR_YELLOW "");
        mode = getchar();

        if((mode == 'u' || mode == 't') && getchar() == '\n')
            break;

        mode = 0;
        printf("" ANSI_COLOR_RESET);
        
        while(getchar() != '\n');

        printf(ANSI_COLOR_RED "Invalid input format" ANSI_COLOR_RESET "\n");
    }

    printf("\n");

    if(mode == 'u')
    {
        printf(ANSI_COLOR_BLUE "###    This is a quadratic equation calculator              ###\n");
        printf("###    Enter a, b, c separated by space or by enter         ###" ANSI_COLOR_RESET "\n");

        struct parametrs library = {NAN, NAN, NAN, NAN, NAN};
        
        enter(&library);

        int res = quadro_equation(&library);

        output(res, &library);
    }
    else
        test();

    return 0;
}