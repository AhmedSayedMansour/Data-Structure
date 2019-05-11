#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    queue <int>q;
    void push(int x)
    {
        int siz=q.size();
        q.push(x);
        while (siz--)
        {
            q.push(q.front());
            q.pop();
        }
    }
    int top()
    {
        return (q.empty())? -1 :q.front();
    }

    void pop()
    {
        q.pop();
    }

};

int main()
{

    Stack a;
    a.push(5);
    a.push(6);
    a.push(7);
    a.push(8);
    cout<<a.top()<<endl;
    a.pop();
    cout<<a.top()<<endl;
    return 0;
}
