#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyCL
{
    private:
    PNODE first;
    PNODE last;
    int iCount;

    public:
    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int,int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

};

DoublyCL :: DoublyCL()
{
    cout<<"Inside Constructor\n";

    first = NULL;
    last = NULL;
    iCount = 0;
}

void :: DoublyCL :: Display()
{
    PNODE temp = NULL;

    temp = NULL;

    temp = first;

    cout<<"<=>";
    do
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    } while (temp != first);
    cout<<"\n";
}

int :: DoublyCL :: Count()
{
    return iCount;
}

void :: DoublyCL :: InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->next = NULL;
    newn->data = no;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
        last = newn;

        first->next = first;
        first->prev = first;
    }
    else 
    {
        newn->next = first;
        newn->prev = last;

        first->prev = newn;
        last->next = newn;

        first = newn;

    }
    iCount++;
}

void :: DoublyCL :: InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->next = NULL;
    newn->data = no;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
        last = newn;

        first->next = first;
        first->prev = first;
    }
    else 
    {
        newn->next = first;
        newn->prev = last;
        last->next = newn;

        last = newn;
        first->prev = last;
    }
    iCount++;
}

void :: DoublyCL :: InsertAtPos(int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;


    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
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

            newn = new NODE;

            newn->next = NULL;
            newn->data = no;
            newn->prev = NULL;

            newn->next = temp->next;
            newn->prev = temp;
            temp->next = newn;
    }
    iCount++;
}

void :: DoublyCL :: DeleteFirst()
{
    if(first == NULL )
    {
        return;
    }
    else if(first == last)
    {
        delete(first);
        delete(last);
        first = NULL;
    }
    else
    {
        first = first->next;
        delete(first->prev);

        first->prev = last;
        last->next = first;
    }
    iCount--;
}

void :: DoublyCL :: DeleteLast()
{
    PNODE temp = NULL;

    if(first == NULL )
    {
        return;
    }
    else if(first == last)
    {
        delete(first);
        delete(last);
        first = NULL;
    }
    else
    {
        temp = last;

        last = last->prev;
        delete(temp);

        last->next = first;
        first->prev = last;
    }
    iCount--;
}
int main()
{
    DoublyCL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements in the linked list are :"<<iRet<<"\n";

    dobj.InsertLast(101);
    dobj.InsertLast(111);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements in the linked list are :"<<iRet<<"\n";

    dobj.InsertAtPos(105,5);
    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements in the linked list are :"<<iRet<<"\n";

    dobj.DeleteFirst();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements in the linked list are :"<<iRet<<"\n";

    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements in the linked list are :"<<iRet<<"\n";



    return 0;
}