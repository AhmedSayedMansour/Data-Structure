#include <bits/stdc++.h>
using namespace std;

struct element
{
    string value;
    int priority;
    element * next;
};

class Priority_queue
{
private:
    element  *head= NULL;
public:
    Priority_queue()
    {

    }

    ~Priority_queue()
    {
        delete head;
    }

    void enqueue(string data, int priority)
    {
        element *temp, *ptr;
        temp = new element;
        temp->value = data;
        temp->priority = priority;

        if (head == NULL || priority < head->priority)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL && ptr->next->priority <= priority)
                ptr=ptr->next;
            temp->next = ptr->next;
            ptr->next = temp;
        }
    }

    void dequeue()
    {

        if (head==NULL)
        {
            cout<< "Empty queue!! \n";
        }
        else
        {
            cout<<head->value;
            element *ptr=head;
            head=head->next;
            free(ptr);
        }
    }
};
int main()
{
    Priority_queue q;
    q.enqueue("world", 10);
    q.enqueue("HI", 15);
    q.enqueue("Hello", 5);
    q.enqueue("*", 1);
    q.dequeue() ;
    cout<<"       ";
    q.dequeue() ;
    cout<<"       ";
    q.dequeue() ;
    cout<<"       ";
    q.dequeue() ;
    cout<<"       ";

    return 0;
}
