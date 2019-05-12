#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template<class T>
class LinkedList
{
public:
    class Node
    {
    public:
        T value;
        Node* next;
        Node(){}
        Node(T v)
        {
            value= v;
        }
    };
private:
    Node* head=NULL;
public:
    LinkedList()
    {
        head = NULL;
    }

    LinkedList<T>& operator = (LinkedList<T> another_list){
        swap(head , another_list.head);
        return *this;
    }

    void addSorted(T v)     //Insertion Sort
    {
        Node * temp, *ptr;
        temp = new Node;
        temp->value=v;

        if (head==NULL)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            ptr=head;
            if (ptr->value>v)
            {
                temp->next=head;
                head=temp;
            }
            else
            {
                while(ptr->next!=NULL&&ptr->next->value<v)
                    ptr=ptr->next;
                temp->next = ptr->next;
                ptr->next = temp;
            }
        }
    }

    Node* get(T v)
    {
        Node *ptr;
        if (head==NULL)
        {
            cout<<"Empty linked list \n";
            return head;
        }
        else
        {
            ptr = head;
            while(ptr->next!=NULL&&ptr->next->value==v)
                ptr=ptr->next;
            return ptr;
        }
    }

    // operator overloading for printing
    friend ostream& operator<<(ostream& out, LinkedList<T> & c)
    {
        Node *p;
        if (c.head==NULL)
        {
            out<<"Empty linked list \n";
            return out;
        }
        else
        {
            p = c.head;
            out<<p->value;
            while(p->next!=NULL)
            {
                out<<" - ";
                p=p->next;
                out<<p->value;
            }
            out<<endl;
            return out;
        }
    }

    ~LinkedList ()
    {
        Node * ptr =head;
        while(ptr!=NULL)
        {
            head=head->next;
            delete ptr;
            ptr=head;
        }
    }
};


#endif  /* LINKED_LIST_H_ */
