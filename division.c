#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    int count = 0,sign=0,i,flag=1,check=0;
     int list1_len = length(head1);
    int list2_len = length(head2);


    if(list2_len > list1_len)
    {
        return 0;
    }

    while(1)
    {
        list1_len = length(head1);
        list2_len = length(head2);
        //comparing the lengths of the arguments
        if(list1_len < list2_len)
        {
            break;
        }
        else if(list1_len > list2_len)
        {
            //performing subtraction
            subtraction(head1,tail1,head2,tail2,headR,tailR,sign);
            delete_list(head1,tail1);

            *head1 = *headR;
            *tail1 = *tailR;

             count++;

            *headR = NULL;
            *tailR = NULL;    
        }
        //if both arguments have same length
        else if(list1_len == list2_len)
        {
            
            Dlist *temp1 = *head1;
            Dlist *temp2 = *head2;
            for(i=0;i<list1_len;i++)
            {
                if(temp1->data > temp2->data)
                {
                    flag=1;
                    break;
                }
                else if(temp1->data < temp2->data)
                {
                    flag=0;
                    break;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            
            if(flag==0)
            {
                break;
            }
            else 
            {
            
            subtraction(head1,tail1,head2,tail2,headR,tailR,sign);
            delete_zero(headR);
            delete_list(head1,tail1);

            *head1 = *headR;
            *tail1 = *tailR;

             count++;

            *headR = NULL;
            *tailR = NULL;
            }


        }
        

    }
    
    return count;
}