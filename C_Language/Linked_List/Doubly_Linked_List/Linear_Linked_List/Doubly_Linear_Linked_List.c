#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->next = NULL;
    newn->data = no;
    newn->prev = NULL;

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

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->next = NULL;
    newn->data = no;
    newn->prev = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}

void InsertAtPos(PPNODE first, int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCount = 0;
    int iCnt = 0;

    iCount = Count(*first);

    if(pos == 1)
    {
        InsertFirst(first,no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(first,no);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt <= pos - 2; iCnt++)
        {
            temp = temp->next; 
        }

        newn = (PNODE)malloc(sizeof(NODE));

        newn->next = NULL;
        newn->data = no;
        newn->prev = NULL;

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        
    }

}

void DeleteFirst(PPNODE first)
{
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL && (*first)->prev == NULL)
    {
        free(first);
    }
    else
    {
        *first = (*first)->next;
        free((*first)->prev);
        (*first)->prev = NULL;
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL && (*first)->prev == NULL)
    {
        free(first);
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE first, int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;

    int iCount = 0;
    int iCnt = 0;

    iCount = Count(*first);

    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iCount)
    {
        DeleteLast(first);
    }
    else
    {

        temp = *first;

        for(iCnt = 1; iCnt <= pos - 2; iCnt++)
        {
            temp = temp->next; 
        }

        target = temp->next ;

        temp->next = target->next;
        free(target);
        temp->next->prev = temp;

        
    }
}

void Display(PNODE first)
{
    printf("NULL");

    while(first != NULL)
    {
        printf("| %d | <=> ",first->data );
        first = first->next;
    }

    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;

}
int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);
    iRet = Count(head);
    printf("Number of elements from the LinkedList are : %d \n", iRet);

    InsertLast(&head,101);
    InsertLast(&head,111);
    Display(head);
    iRet = Count(head);
    printf("Number of elements from the LinkedList are : %d \n", iRet);

    InsertAtPos(&head,105,5);
    Display(head);
    iRet = Count(head);
    printf("Number of elements from the LinkedList are : %d \n", iRet);

    DeleteAtPos(&head,5);
    Display(head);
    iRet = Count(head);
    printf("Number of elements from the LinkedList are : %d \n", iRet);


    DeleteFirst(&head);
    Display(head);
    iRet = Count(head);
    printf("Number of elements from the LinkedList are : %d \n", iRet);

    DeleteLast(&head);
    Display(head);
    iRet = Count(head);
    printf("Number of elements from the LinkedList are : %d \n", iRet);

    return 0;
}