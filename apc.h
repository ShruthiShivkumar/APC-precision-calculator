#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>


#define SUCCESS 0
#define FAILURE -1


typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}Dlist;


/*Include the prototypes here*/

/*read and validate*/
int read_and_validate(int argc,char**argv);

/*Insert first*/
int insert_first(Dlist **head, Dlist **tail, int data);

/*Insert last*/
int insert_last(Dlist **head, Dlist **tail, int data);

/*print list*/
void print_list(Dlist *head);

/*Addition*/
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

/*Subtraction*/
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR,int sign);

/*multiplication*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR1, Dlist **tailR1, Dlist **headR2, Dlist **tailR2);

/*division*/
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

void insert_digit(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char **argv);

/*Validate cases for subtraction*/
int validate_subtraction(char **argv,int *sign);

/*delete zeros from the first*/
void delete_zero(Dlist **head);

/*delete list*/
int delete_list(Dlist **head, Dlist **tail);

/*Find length of list*/
int length(Dlist **head);


#endif