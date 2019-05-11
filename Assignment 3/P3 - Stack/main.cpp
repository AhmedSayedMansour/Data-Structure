#include <iostream>
#include<bits/stdc++.h>

int MAXSIZE =1000;

using namespace std;

template < class T>
class Stack
{
private:
    T *num = new T[MAXSIZE];
    int SIZE;  //Defines Size.
public:
    //Default Constructor.
    Stack()
    {
        SIZE = 0;
    }
    //constructs a stack having "initial_size" elements whose values are "value".
    Stack(T value , int initialSize)
    {
        SIZE = initialSize;
        for(int i = 0 ; i < SIZE ; i++)
        {
            num[i] = value;
        }
    }

    //a destructor to clear the stack and leave no memory leaks.
    ~Stack()
    {
        delete []num;
    }

    //returns the top element by reference.
    T &Top()
    {
        if(SIZE == 0)
            cout <<"Stack is empty !!"<<endl;
        else
            return num[SIZE];
    }

    //removes the top element.
    void Pop()
    {
        if(SIZE == 0)
            cout <<"Stack is empty!!"<<endl<<"there is no elements to delete!"<<endl;
        else
        {
            SIZE--;
        }
    }

    //adds an element to the top of the stack.
    void Push(T value)
    {
        num[++SIZE] = value;
    }
    //returns the number of elements in the stack.
    int Size()
    {
        return SIZE;
    }
};
int main()
{

    Stack<int>ST(20 , 5);

    cout <<"\nSize of Stack before popping : " <<endl;
    cout << ST.Size();
    ST.Pop();
    ST.Pop();
    cout <<"\nSize of Stack after popping : " <<endl;
    cout << ST.Size();
    cout <<"\nLast Added element : "<<endl;
    cout << ST.Top();


   cout << "\n\n"<<endl;


    Stack<int>ST2;
    ST2.Push(25);
    ST2.Push(65);
    ST2.Push(35);
    ST2.Push(15);
    cout <<"\nSize of Stack before popping : " <<endl;
    cout << ST2.Size();
    cout <<"\nPopping last added element : "<<endl;
    cout << ST2.Top();
    ST2.Pop();
    cout <<"\nSize of Stack after popping : " <<endl;
    cout << ST2.Size();
    cout <<"\nLast Added element : "<<endl;
    cout << ST2.Top();

    return 0;
}
