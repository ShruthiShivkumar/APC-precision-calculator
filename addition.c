#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    int num1,num2,sum;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int carry = 0,rem=0;
    while(temp1!=NULL || temp2!=NULL)
    {
          if(temp1==NULL)
          {
            num1 = 0;
          }
          else
          {
            num1 = temp1->data;
          }
          if(temp2==NULL)
          {
            num2 = 0;
          }
          else
          {
            num2 = temp2 -> data;
          }
          //addition operation
          sum = num1 + num2 + carry;
          rem = sum % 10;
          carry = sum/10;
          //result using insert first
          if(carry==0)
          {
             if(insert_first(headR,tailR, sum)==FAILURE)
             {
                return FAILURE;
             }
          }
          else
          {
            if(insert_first(headR, tailR, rem)==FAILURE)
            {
                return FAILURE;
            }
          }
        
        if (temp1 != NULL) 
          temp1 = temp1->prev; 
        if (temp2 != NULL) 
          temp2 = temp2->prev;
        
    }
    if(carry!=0)
    {
      insert_first(headR,tailR, carry);

    }
    delete_zero(headR);
    return SUCCESS;
}