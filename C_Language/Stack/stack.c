#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

void push(struct node **first,int no)
{
    struct node *newn = NULL;

    newn = (struct node *)malloc(sizeof(struct node));

    newn->next = NULL;
    newn->data = no;

    if(*first == NULL)
    {
        *first = newn; 
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }
}

void pop(struct node **first)
{
    struct node *temp = NULL;

    if(*first == NULL )
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first)->next;
        free(temp);
    }
}

void Display(struct node *first)
{
    while(first != NULL)
    {
        printf("| %d | ->",first->data);
        first = first->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node *head = NULL;

    push(&head,51);
    push(&head,21);
    push(&head,11);

    Display(head);

    pop(&head);
    Display(head);



    return 0;
}