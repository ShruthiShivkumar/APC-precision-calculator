/*Documentation
Name : Shruthi Shivkumar
Date : 21 - 12 -2024
DES  : Arbitrary precision calculator
*/

#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;
    Dlist *headR1 = NULL,*tailR1 = NULL;
    Dlist *headR2 = NULL,*tailR2 = NULL;
    
    int sign=0,count;

    if (read_and_validate(argc, argv) != SUCCESS)
    {
        return 0;
    }
    
    char operator = argv[2][0];

    switch (operator)
    {
        //addition
        case '+':
            insert_digit(&head1,&tail1,&head2,&tail2,argv);
            if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
            {
                printf("Result = ");
                print_list(headR);
                printf("Addition operation performed successfully\n");
            }
            else
            {
                printf("Addition operation failed\n");
            }
            break;
        //subtraction
        case '-':
            if(validate_subtraction(argv,&sign)==FAILURE)
            {
                printf("ERROR : Subtraction operation failed\n");
                return 0;
            }
            else if(validate_subtraction(argv,&sign)!=FAILURE)
            {
                if(sign==-1)
                {
                    insert_digit(&head1,&tail1,&head2,&tail2,argv);
                    Dlist *temp_head = head1;
                    Dlist *temp_tail = tail1; 
                    head1 = head2; 
                    tail1 = tail2; 
                    head2 = temp_head; 
                    tail2 = temp_tail; 
                    
                }
                else
                {
                  insert_digit(&head1,&tail1,&head2,&tail2,argv);
                }

                if (subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR,sign) == SUCCESS)
               {
                printf("Result = ");
                 print_list(headR);
                  printf("Subtraction operation performed successfully\n");
               }
            }
            break;
        //multiplication
        case 'x':
            insert_digit(&head1,&tail1,&head2,&tail2,argv);
            if(multiplication(&head1, &tail1, &head2, &tail2, &headR1, &tailR1, &headR2, &tailR2)==SUCCESS)
            {
                printf("Result = ");
                print_list(headR1);
                printf("Multiplication operation performed successfully\n");
            }
            else
            {
                printf("Multiplication operation failed\n");   
            }
            break;
        //division
        case '/':
            insert_digit(&head1,&tail1,&head2,&tail2,argv);
            if (head2 == NULL || head2->data == 0) 
            { 
                    printf("Not defined\n"); 
                    printf("Division operation failed\n");
                    return 0;
            }
            count = division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            printf("Result = %d\n",count);
            printf("Division operation performed successfully\n");
                
            break;

        default:
            printf("Invalid Input:-( Try again...\n");
    }

    return 0;
}
