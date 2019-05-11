#include <bits/stdc++.h>
using namespace std;
template <class T>
class Queue
{

public:
    T *q;
    int Size ;

    Queue()
    {
        Size=0;
        q = new T[1000];
    }

    Queue(T value, int initial_Size)
    {
        Size=initial_Size;
        q = new T[initial_Size];
        for (int i=0; i<Size; i++)
            q[i]=value;
    }
    ~Queue()
    {
        Size=0;
        delete []q;
    }

    T& front()
    {
        return q[0];
    }

    void push(T value)
    {
        q[Size++]=value;
    }

    void pop()
    {
        for (int i=1 ; i<Size; i++)
            q[i-1]=q[i];
        Size--;
    }
    int get_Size()
    {
        return Size;
    }

};
int main()
{

    Queue<int> a;

    a.push(5);
    a.push(7);
    a.push(8);
    a.push(9);
    cout<<a.get_Size()<<endl;
    cout<<a.front()<<endl;
    a.pop();
    cout<<a.front()<<endl;
    cout<<a.get_Size()<<endl;

    return 0;
}
