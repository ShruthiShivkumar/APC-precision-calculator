#include "apc.h"

  int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR1, Dlist **tailR1,Dlist **headR2, Dlist **tailR2 )
{
    Dlist *temp1 = *tail1,*temp2 = *tail2;
    Dlist *backup_head = NULL, *backup_tail = NULL;
    int num1,num2,sum=0,carry=0,rem=0,count=0;
    while(temp2 != NULL)
    {
        temp1 = *tail1;
        //first step of multiplication
        if(count==0)
        {
            while(temp1!=NULL)
            {
                
                num1 = temp1 -> data;
                num2 = temp2 -> data;
                sum = (num1 * num2) + carry;
                rem = sum % 10;
                carry = sum /10;

                if(insert_first(headR1,tailR1,rem)==FAILURE)
                {
                    return FAILURE;
                } 

                temp1 = temp1 -> prev;
            }

             
        }

        else
        {
            //storing the result in headR2 from step2
            while(temp1!=NULL)
            {
                num1 = temp1 -> data;
                num2 = temp2 -> data;
                sum = (num1 * num2) + carry;
                rem = sum % 10;
                carry = sum /10;

                if(insert_first(headR2,tailR2,rem)==FAILURE)
                {
                    return FAILURE;
                } 

                temp1 = temp1 -> prev;
            }
             
                
            
        int i;

      //carry in the result            
        if(count!=0)
        {
            for(i=0;i<count;i++)
            {
                if(insert_last(headR2,tailR2,0)==FAILURE)
                {
                    return FAILURE;
                }
            }
        }
            
        //addition operation
        if(addition(headR1,tailR1,headR2,tailR2,&backup_head,&backup_tail)==FAILURE)
        {
            return FAILURE;
        }
         //deleting list headR1 and headR2
        if(delete_list(headR1,tailR1)==FAILURE)
        {
            return FAILURE;
        }
        if(delete_list(headR2,tailR2)==FAILURE)
        {
            return FAILURE;
        }
         //updating values
        *headR1 = backup_head;
        *tailR1 = backup_tail;

        
        backup_head = NULL;
        backup_tail = NULL;
    }
        
        temp2 = temp2 -> prev;
        count++;
             

    }

    if(carry!=0)
    {
        if(insert_first(headR1,tailR1,carry)==FAILURE)
        {
            return FAILURE;
        } 
        carry = 0;
    }
    delete_zero(headR1);
    return SUCCESS;
  } 
    

    


