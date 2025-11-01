#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int Count(PNODE first, PNODE last)
{
    PNODE temp = NULL;
    int iCount = 0;

    temp = first;

    do
    {
        iCount++;
        temp = temp->next;
    } while (temp != last->next);

    return iCount;
} //End of Count function

void InsertFirst(PPNODE first,PPNODE last, int no)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
        (*last)->next = *first;
    }
}//InsertFirst function end

void InsertLast(PPNODE first,PPNODE last, int no)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        (*last)->next = newn;
        *last = newn;
    }
}  //InsertLast function end

void InsertAtPos(PPNODE first,PPNODE last,int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCount = 0, i = 0;

    iCount = Count(*first,*last);

    if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first,last,no);
    }
    else
    {
        temp = *first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;

    }
}

void DeleteFirst(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first)->next;
        (*last)->next = *first;
        free(temp);
    }
}

void DeleteLast(PPNODE first,PPNODE last)
{
    PNODE temp = NULL;

    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first == *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != (*last)->next)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = *first;
        *last = temp;
    }
}

void DeleteAtPos(PPNODE first,PPNODE last,int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    PNODE target = NULL;
    int iCount = 0, i = 0;

    iCount = Count(*first,*last);

    if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first,last);
    }
    else
    {
        temp = *first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        free(target);
    }
}

void Display(PNODE first, PNODE last)
{
    PNODE temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else
    {
        temp = first;

        do
        {
            printf("| %d | ->",temp->data);
            temp = temp->next;
        } while (temp != last->next);
        printf("\n");
    }
    
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;
    int iRet = 0;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements in the LinkedList are : %d\n",iRet);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements in the LinkedList are : %d\n",iRet);

    InsertAtPos(&head,&tail,105,5);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements in the LinkedList are : %d\n",iRet);

    DeleteAtPos(&head,&tail,5);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements in the LinkedList are : %d\n",iRet);

    DeleteFirst(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements in the LinkedList are : %d\n",iRet);

    DeleteLast(&head,&tail);
    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of elements in the LinkedList are : %d\n",iRet);

    return 0;
}