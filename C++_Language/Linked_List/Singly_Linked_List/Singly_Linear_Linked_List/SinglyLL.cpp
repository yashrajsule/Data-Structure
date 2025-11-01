#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLL
{
    private :
    PNODE first;
    int iCount;

    public:
    SinglyLL();
    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPOs(int,int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int); 

    void Display();
    int Count();

};

SinglyLL :: SinglyLL()
{
    cout<<"Inside Constructor\n";

    first = NULL;
    iCount = 0;
}


void :: SinglyLL :: InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn -> next = NULL;
    newn -> data = no;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn -> next = first;
        first = newn;
    }
    iCount++;
}

void :: SinglyLL :: InsertLast(int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = new NODE;

    newn -> next = NULL;
    newn -> data = no;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp -> next = newn; 
    }
    iCount++;
}

void :: SinglyLL :: InsertAtPOs(int no , int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > iCount + 1))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {

        temp = first;

        for(iCnt = 1; iCnt <= pos - 2; iCnt++)
        {
            temp = temp->next;
        }

        newn =new NODE;

        newn->data = no;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;
}

void :: SinglyLL :: DeleteFirst()
{
    PNODE temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if((first) -> next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        temp = first;

        first = (first)->next;
        delete(temp);
    }
    iCount--;

}

void :: SinglyLL :: DeleteLast( )
{
    PNODE temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if((first)-> next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    iCount--;

}

void :: SinglyLL :: DeleteAtPos(int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > iCount))
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {

        temp = first;

        for(iCnt = 1; iCnt <= pos - 2; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
}
iCount--;
}
void :: SinglyLL :: Display()
{
    PNODE temp = NULL;

    temp = first;
    do
    {
        cout<<"|"<<temp->data<<"| -> ";
        temp = temp -> next;
    }while((temp != NULL));
    cout<<"NULL\n";
}

int :: SinglyLL :: Count()
{
    return iCount;
}

int main()
{
    SinglyLL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    sobj.InsertLast(101);
    sobj.InsertLast(111);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    sobj.InsertAtPOs(105,5);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    sobj.DeleteAtPos(5);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    sobj.DeleteFirst();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";

    sobj.DeleteLast();
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linked list are : "<<iRet<<"\n";



    return 0;
}