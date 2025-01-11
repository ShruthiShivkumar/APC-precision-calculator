#include "apc.h"

int insert_first(Dlist **head, Dlist **tail, int data)
{
    //creating new node
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
       return FAILURE;
    }
    new->data = data;
    new -> prev = NULL;
    new -> next = *head;
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    (*head)->prev = new;
    *head = new;
    return SUCCESS;
}


int insert_last(Dlist **head, Dlist **tail, int data)
{
    //creating new node
    Dlist *new = malloc(sizeof(Dlist));
    if(new==NULL)
    {
        return FAILURE;
    }
    new -> data = data;
    new -> prev = *tail;
    new -> next = NULL;
    //if list is empty
    if(*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    //updating the values
    (*tail)->next = new;
    *tail = new;
    return SUCCESS;

}

void insert_digit(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char **argv)
{
    int i = 0;

    // Insert into the first list
    while (argv[1][i] != '\0')
    {
        int data = argv[1][i] - '0';
        insert_last(head1, tail1, data);
        i++;
    }
    printf("Number 1 : ");
    print_list(*head1);

    i = 0; 

    // Insert into the second list
    while (argv[3][i] != '\0')
    {
        int data = argv[3][i] - '0';
        insert_last(head2, tail2, data);
        i++;
    }
    printf("Number 2 : ");
    print_list(*head2);
}

void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
        
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
		    
	    }
    	printf("\n");
    }
}

void delete_zero(Dlist **head)
{
    //delete zeroes from the first

   int flag = 0;
   Dlist *temp;

   while(*head)
   {
    if(flag==1)
    {
        break;
    }
    if((*head)->data > 0)
    {
        flag=1;
    }
    else if(((*head)->next)==NULL)
    {
        break;
    }
    else
    {
        temp = *head;
        *head = (*head) -> next;
        (*head) -> prev = NULL;
        free(temp);
    }
   }
   
}


int delete_list(Dlist **head, Dlist **tail)
{
    //checking if head is NULL
     if(*head == NULL)
    {
        return FAILURE;
    }
    //traversing the list
   while((*head) -> next != NULL)
   {
     *head=(*head) -> next;
     free((*head) -> prev);
   }

   free(*head);
   *head=NULL;
   *tail=NULL;

   return SUCCESS;
}


int length(Dlist **head)
{
    int count = 0;
    if(*head == NULL)
    {
        return 0;
    }
    Dlist *temp = *head;
    while(temp!=NULL)
    {
        count++;
        temp = temp -> next;
    }
    return count;

}