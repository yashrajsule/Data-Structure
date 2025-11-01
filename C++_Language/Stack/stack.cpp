#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class StackX
{
    private:
    PNODE first;

    public:
    StackX();

    void push(int);
    void pop();
    void Display();
};

StackX :: StackX()
{
    cout<<"Inside constructor.\n";
    first = NULL;
}

void :: StackX :: Display()
{
    PNODE temp = NULL;

    temp = first;
    do 
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }while(temp != NULL);
    cout<<"NULL\n";
}

void :: StackX :: push(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->next = NULL;
    newn->data = no;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
}

void :: StackX :: pop()
{
    PNODE temp = NULL;

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

        first = first->next;
        delete(temp);
    }
}
int main()
{
    StackX sobj;

    sobj.push(11);
    sobj.push(21);
    sobj.push(51);

    sobj.Display();

    sobj.pop();
    sobj.Display();

    sobj.push(101);
    sobj.push(111);
    sobj.Display();

    return 0;
}