 #include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, int sign)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    
    int num1, num2, borrow = 0, sub;
    //subtraction operation
    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1 == NULL)
        {
            num1 = 0;
        }
        else
        {
            num1 = temp1->data;
        }

        if (temp2 == NULL)
        {
            num2 = 0;
        }
        else
        {
            num2 = temp2->data;
        }

        if (borrow == 1)
        {
            num1 = num1 - 1; 
            borrow = 0;
        }

        if (num1 < num2)
        {
            num1 = num1 + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        

        sub = num1 - num2;
        //inserting first operation for result
        if (insert_first(headR, tailR, sub) == FAILURE)
        {
            return FAILURE;
        }

        if (temp1 != NULL) 
          temp1 = temp1->prev;
        if (temp2 != NULL) 
          temp2 = temp2->prev;
    }

    //negative result
    if (sign == -1)
    {
        printf("-");
    }
    //deleting zeroes from the front
    delete_zero(headR);

    if (*headR == NULL) 
    { 
        insert_first(headR, tailR, 0);
    } 

    
    return SUCCESS;
} 




            