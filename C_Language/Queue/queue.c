#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void enqueue(struct node **first, int no)
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

void dequeue(struct node **first)
{
    struct node *temp = NULL;

    if(*first == NULL)
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

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;

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

    enqueue(&head,11);
    enqueue(&head,21);
    enqueue(&head,51);
    Display(head);

    dequeue(&head);
    Display(head);

    return 0;
}