#include <iostream>
#include <stack>

using namespace std;

bool isPalindrome(string a);

int main()
{
    string a ="abba",b="abab",c="dad";
    cout<<isPalindrome(a)<<endl;
    cout<<isPalindrome(b)<<endl;
    cout<<isPalindrome(c)<<endl;
    return 0;
}

bool isPalindrome(string a){
    stack<char> s,s2;
    bool is= true;

    for(int i=0 ; i<a.size();++i)  s.push(a[i]);

    for(int i=a.size()-1 ; i>=0;--i)s2.push(a[i]);
    for(int i=0 ; i<a.size();++i){
        if(s.top()!=s2.top()){
            is = false ;
            break;
        }
        s.pop();
        s2.pop();
    }
    return is;
}
