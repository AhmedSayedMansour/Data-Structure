/// Title:   Assignment 1 - Assignment 1 - Problem 3
/* programmers: Ahmed Sayed Mansour   20170022
				Fatma Ashraf Ramadan  20170192
				Ibrahim Ramadan Abdou 20170002
*/
/// last edit : 03/03/2019

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StudentName
{
private:
    string Name;
public:
    StudentName(string name)
    {
        int numofspaces=0,posoflast=0;
        for(int i=0; i<name.length(); ++i)
        {
            if (name[i]==' ')
            {
                ++numofspaces;
                posoflast=i;
            }
        }
        if (numofspaces<2)
        {
            if(numofspaces==0)
                Name=name+" "+name+" "+name;
            else
                Name=name+name.substr(posoflast);
        }
        else
            Name=name;
    }
    void print()
    {
        vector <string> Names;
        string name="";
        for(int i=0; i<Name.length(); ++i)
        {
            if (Name[i]==' ')
            {
                Names.push_back(name);
                name="";
            }
            else if(i==Name.length()-1)
            {
                name+=Name[i];
                Names.push_back(name);
            }
            else
                name+=Name[i];
        }
        int j=1;
        for(int i=0; i<Names.size(); ++i)
        {
            cout<<j<<") "<<Names[i]<<endl;
            ++j;
        }
    }
    bool Replace(int i,int j)
    {
        vector <string> Names;
        string name="";
        for(int i=0; i<Name.length(); ++i)
        {
            if (Name[i]==' ')
            {
                Names.push_back(name);
                name="";
            }
            else if(i==Name.length()-1)
            {
                name+=Name[i];
                Names.push_back(name);
            }
            else
                name+=Name[i];
        }
        if(i > Names.size() || j > Names.size())
        {
            return false;
        }
        else
        {
            string s=Names[j-1];
            Names[j-1]=Names[i-1];
            Names[i-1]=s;
            string f;
            for(int i = 0 ; i < Names.size() ; i++)
            {
                f+=Names[i] + " ";
            }
            Name = f;
            cout << Name<<endl;
            return true;
        }
    }
};

int main()
{

    StudentName test1("Ahmed Sayed Mansour");
    if(test1.Replace(1,3))
    {
        test1.print();
        cout <<endl;
    }


    StudentName test2("Ahmed Sayed Mansour");
    if(test2.Replace(2,3))
    {
        test2.print();
        cout <<endl;
    }
    StudentName test3("Fatma Ashraf");
    if(test3.Replace(3,1))
    {
        test3.print();
        cout <<endl;
    }

    StudentName test4("Ahmed");
    if(test4.Replace(1,3))
    {
        test4.print();
        cout <<endl;
    }

    StudentName test5("Ibrahim ramadan");
    if(test5.Replace(1,3))
    {
        test5.print();
        cout <<endl;
    }

    return 0;
}
