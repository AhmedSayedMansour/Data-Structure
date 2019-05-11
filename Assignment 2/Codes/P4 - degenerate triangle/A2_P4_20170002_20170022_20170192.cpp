/*
Problem 4

Programmers:
        Ahmed Sayed Mansour   20170022
        Fatma Ashraf Ramadan  20170192
        Ibrahim Ramadan Abdou 20170002

*/
#include <bits/stdc++.h>
using namespace std;
class triangle
{
protected:
    vector<int>s1;
    vector<int>s2;
    vector<int>s3;
public:
    void getsidesfromvector(vector<int>v)
    {
        for (int i=0; i<v.size()-2; i++)
        {
            for (int j=i+1; j<(v.size()-1); j++)
            {
                for (int k=j+1; k<v.size(); k++)
                {
                    s1.push_back(v[i]);
                    s2.push_back(v[j]);
                    s3.push_back(v[k]);
                }
            }
        }
    }

    void print(int i)
    {
        cout<<s1[i]<<"   "<<s2[i]<<"   "<<s3[i]<<endl;
    }

    int non_degenerate()
    {
        int x=0;
        for (int i=0; i<s1.size(); i++)
        {
            if ( ( (s1[i]+s2[i])> s3[i]) && ((s1[i]+s3[i])>s2[i]) && ((s2[i]+s3[i])>s1[i]) )
            {
                print(i);
                x++;
            }
        }
        return x;
    }
};
int main()
{
    vector <int>triangle1{1,2,3,4,5};
    triangle a;
    a.getsidesfromvector(triangle1);
    cout<<"we can get: "<<a.non_degenerate()<<"  non_degenerate triangles from above sides"<<endl;
    return 0;
}
