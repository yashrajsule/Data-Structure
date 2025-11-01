#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class QueueX
{
    private:
    PNODE first;

    public:
    QueueX();

    void enqueue(int);
    void dequeue();
    void Display();
};

QueueX :: QueueX()
{
    cout<<"Inside constructor.\n";
    first = NULL;
}

void :: QueueX :: Display()
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

void :: QueueX :: enqueue(int no)
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

void :: QueueX :: dequeue()
{
    PNODE temp = NULL;

    if(first == NULL)
    {
        return;
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
}
int main()
{
    QueueX sobj;

    sobj.enqueue(11);
    sobj.enqueue(21);
    sobj.enqueue(51);

    sobj.Display();

    sobj.dequeue();
    sobj.Display();

    return 0;
}