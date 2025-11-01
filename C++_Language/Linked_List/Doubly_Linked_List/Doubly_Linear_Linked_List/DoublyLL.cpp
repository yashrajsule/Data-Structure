#include<iostream>
using namespace std;

template <class T>
struct node 
{
    T data;
    struct node<T> *next;
    struct node<T> *prev;
};

template <class T>
class DoublyLL
{
    private:
        struct node<T> * first;
        int iCount;

    public:
        DoublyLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    cout<<"Inside Constructor.\n";
    first = NULL;
    iCount = 0;
};

template <class T>
void :: DoublyLL<T> :: InsertFirst(T no)
{
    struct node<T> * newn = NULL;

    newn = new struct node<T>;

    newn->next = NULL;
    newn->data = no;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void :: DoublyLL<T> :: InsertLast(T no)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;

    newn = new struct node<T>;

    newn->next = NULL;
    newn->data = no;
    newn->prev = NULL;

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
        newn->prev = temp;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void :: DoublyLL<T> :: InsertAtPos(T no, int pos)
{
    struct node<T> * newn = NULL;
    struct node<T> * temp = NULL;
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

        newn = new struct node<T>;

        newn->next = NULL;
        newn->data = no;
        newn->prev = NULL;

        newn->next = temp->next;
        temp->next = newn;
        temp->next->prev = newn;
        newn->prev = temp;

    }
    iCount++;
}

template <class T>
void :: DoublyLL<T> :: DeleteFirst()
{

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        first = first->next;
        delete(first->prev);
        first->prev = NULL;
    }
    iCount--;

}

template <class T>
void :: DoublyLL<T> :: DeleteLast()
{
    struct node<T> * temp = NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete(first);
        first = NULL;
    }
    else
    {
        temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    iCount--;

}

template <class T>
void :: DoublyLL<T> :: DeleteAtPos(int pos)
{
    struct node<T> * temp = NULL;
    struct node<T> * target = NULL;

    int iCnt = 0;

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
        target->next->prev = temp;
        temp->next = target->next;

        delete(target);

    }
    iCount--;
}

template <class T>
void :: DoublyLL<T> :: Display()
{
    struct node<T> * temp = NULL;

    temp = first;

    cout<<"NULL";
    do
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    } while (temp != NULL);
    cout<<"NULL\n";
}

template <class T>
int :: DoublyLL<T> :: Count()
{
    return iCount;
}

int main()
{
    DoublyLL<float> dobj;
    int iRet = 0;

    dobj.InsertFirst(51.5);
    dobj.InsertFirst(21.5);
    dobj.InsertFirst(11.5);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements of linked list are :"<<iRet<<"\n";

    dobj.InsertLast(101.5);
    dobj.InsertLast(111.5);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements of linked list are :"<<iRet<<"\n";

    dobj.InsertAtPos(105.5,5);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements of linked list are :"<<iRet<<"\n";

    dobj.DeleteAtPos(5);

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements of linked list are :"<<iRet<<"\n";

    dobj.DeleteFirst();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements of linked list are :"<<iRet<<"\n";

    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();
    cout<<"Number of elements of linked list are :"<<iRet<<"\n";

    return 0;
}