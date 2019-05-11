#include <iostream>
#include<bits/stdc++.h>

using namespace std;

//Function to test if its parameters are opening and closing parenthesis.
bool  ArePAirs(char openning, char closing)
{
    if(openning == '(' && closing == ')')
        return true;

    if(openning == '[' && closing == ']')
        return true;

    if(openning == '{' && closing == '}')
        return true;

}

//Function to check the whole string validation.
bool isValid(string txt)
{
    stack<char>test;
    bool Comment = false;   //To ensure that the comment is closed.
    for(int i = 0 ; i < txt.size() ; i++)
    {
        if(!Comment && txt[i] != '*')   /**/
        {
            if(txt[i]=='(' || txt[i] == '{' || txt[i] == '[')
            {
                test.push(txt[i]);  //pushing the opening parenthesis to the stack.
            }

            else if((txt[i]=='/') && (txt[i+1]=='*'))
            {
                test.push(txt[i]);
                test.push(txt[i+1]);
                i+=2;           //because we took two elements of the string.
                Comment = true; //means now we have comment opened .
            }
            else if(txt[i]==')' || txt[i] == '}' || txt[i] == ']')
            {
                //checking if the stack is empty or the parenthesis not pairs.
                if((test.empty()) || !ArePAirs(test.top(), txt[i]) )
                    return false;
                else
                    test.pop();
            }
        }
        //handling comment closing.
        else if((i+1 != txt.size())&& (txt[i]=='*') && (txt[i+1]=='/') )
        {
            if(!test.empty() && test.top() == txt[i])
            {
                test.pop();//deleting from stack.
                test.pop();
                i++;
                Comment = false; //Now we found the comment closing.
            }
            else
                return false;
        }

    }
    if (!test.empty()) return false;

    return true;
}

int main()
{

//    string text;
//    cout << "Enter your text : "<<endl;
//    cin >> text;
//    if(isValid(text))
//        cout << "Valid"<<endl;
//    else
//        cout << "InValid"<<endl;


    //Assignment Tests.
    string test = "([{}])(){}[]{[]} ";
    if(isValid(test))
        cout << "Valid"<<endl;
    else
        cout << "InValid"<<endl;


    string test1 = "({)}  ";
    if(isValid(test1))
        cout << "Valid"<<endl;
    else
        cout << "InValid"<<endl;


    string test2 = " ({/*)}]]]]]]}*/}) ";
    if(isValid(test2))
        cout << "Valid"<<endl;
    else
        cout << "InValid"<<endl;


    string test3 = "({/*[][[]]]]]}) ";
    if(isValid(test3))
        cout << "Valid"<<endl;
    else
        cout << "InValid"<<endl;


    string test4 = "  [{/*******/}]   ";
    if(isValid(test4))
        cout << "Valid"<<endl;
    else
        cout << "InValid"<<endl;


    return 0;
}
