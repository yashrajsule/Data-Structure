#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCL
{
    private:
    PNODE first;
    PNODE last;
    int iCount;

    public:
    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(int);
    void InsertLast(int);
    void InsertAtPos(int , int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

};

SinglyCL :: SinglyCL()
{
    cout<<"Inside Constructor\n";

    first = NULL;
    last = NULL;
    iCount = 0;
}

void :: SinglyCL :: Display()
{
    PNODE temp = NULL;

    temp = first;

    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    } while (temp != first);
    cout<<"\n";
    
}

int :: SinglyCL :: Count()
{
    return iCount;
}

void :: SinglyCL :: InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->next = NULL;
    newn->data = no;

    if(first == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }
    iCount++;
}

void :: SinglyCL :: InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->next = NULL;
    newn->data = no;

    if(first == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        last->next = newn;
        last = newn;
    }
    iCount++;
}

void :: SinglyCL :: DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete(first);
        first = NULL;
        last = NULL;
    }
    else
    {
        PNODE temp = NULL;

        temp = first;

        first = first->next;
        last->next = first;
        delete(temp);
    }
    iCount--;
}

void :: SinglyCL :: DeleteLast()
{
    PNODE temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete(first);
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }
        delete(last);
        temp->next = first;
        last = temp;
    }
    iCount--;
}

void :: SinglyCL :: InsertAtPos(int no, int pos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int iCnt = 0;

    if(pos < 1 && pos > iCount+1)
    {
        cout<<"Invalid Position\n";
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

        newn = new NODE;

        newn->next = NULL;
        newn->data = no;

        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;
}

void :: SinglyCL :: DeleteAtPos(int pos)
{
    PNODE temp = NULL;
    PNODE target = NULL;
    int iCnt = 0;

    if(pos < 1 && pos > iCount)
    {
        cout<<"Invalid Position\n";
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
        delete(target);
    }
    iCount--;
}


int main()
{
    SinglyCL sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linkedlist are :"<<iRet<<"\n";

    sobj.InsertLast(101);
    sobj.InsertLast(111);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linkedlist are :"<<iRet<<"\n";

    sobj.InsertAtPos(105,5);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linkedlist are :"<<iRet<<"\n";

    sobj.DeleteAtPos(5);
    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linkedlist are :"<<iRet<<"\n";

    sobj.DeleteFirst();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linkedlist are :"<<iRet<<"\n";

    sobj.DeleteLast();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of elements in the linkedlist are :"<<iRet<<"\n";


    return 0;
}