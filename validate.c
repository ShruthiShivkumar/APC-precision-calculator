 #include "apc.h"
 #include <string.h>

int read_and_validate(int argc, char **argv)
{
    int i = 0, j = 0;
    //checking for argument count 
    if (argc != 4)
    {
        printf("ERROR: Enter proper arguments\n");
        return FAILURE;
    }
    //checking for arithmetic operators
    if (!((argv[2][0] == '+') || (argv[2][0] == '-') || (argv[2][0] == 'x') || (argv[2][0] == '/')))
    {
        printf("ERROR: Enter proper operator\n");
        return FAILURE;
    }
   //checking if first argument has digits or not
    while (argv[1][i] != '\0')
    {
        if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
        {
            printf("ERROR: Enter digits only\n");
            return FAILURE;
        }
        i++;
    }
    //checking if third argument has digits or not
    while (argv[3][j] != '\0')
    {
        if (!(argv[3][j] >= '0' && argv[3][j] <= '9'))
        {
            printf("ERROR: Enter digits only\n");
            return FAILURE;
        }
        j++;
    }

    return SUCCESS;
}
 
int validate_subtraction(char **argv,int *sign)
{
    //checking for the greater argument value and returning the sign value
    if(strlen(argv[3])>strlen(argv[1]))
    {
       *sign = -1;
       return SUCCESS;
    }
    else if(strlen(argv[3])<strlen(argv[1]))
    {
        *sign = 1;
        return SUCCESS;
    }
    else
    {
        if(strcmp(argv[1],argv[3])<0)
        {
            *sign = -1;
            return SUCCESS;
        }
        else if(strcmp(argv[1],argv[3])>0)
        {
            *sign = 1;
            return SUCCESS;
        }
        else
        {
            *sign = 1;
            return SUCCESS;
        }
    }
    return FAILURE;
}


