/*
Problem 3

Programmers:
        Ahmed Sayed Mansour   20170022
        Fatma Ashraf Ramadan  20170192
        Ibrahim Ramadan Abdou 20170002

*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int i=0;

class searcher
{
public:
    vector <string>v;
    void load_data(int x)
    {
        ifstream file("words.txt",ios::in);
        string a;
        for (int i=0; i<x; i++)
        {
            file>>a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        file.close();
    }

    int BinarySearch(string key,int low, int high)
    {
        i++;
        int x;
        if (low > high)
        {
            x=i;
            i=0;
            cout<<"Not found"<<endl;
            return x;
        }
        int mid = (low + high) / 2;
        if (key == v[mid])
        {
            i++;
            cout<<v[mid]<<" founded in place "<<mid<<endl;
            x=i;
            i=0;
            return x;
        }
        if (key < v[mid])
        {
            i++;
            return BinarySearch(key,low, mid - 1);
        }
        else
        {

            i++;
            return BinarySearch(key,mid + 1, high);
        }
    }

    void test_time_performance(string key,int low, int high)
    {
        ofstream outfile("plotting.csv",ios::binary);
        outfile<<"steps"<<","<<"Time"<<"\n";
        auto start = high_resolution_clock::now();
        outfile<<BinarySearch( key, low,  high)<<",";
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        outfile<<duration.count()<<"\n";

        auto sum=0;
        int sum_of_comparisons=0;
        for (int i=0; i<high; i++)
        {
            int randNum = rand()%(high + 1);
            auto start = high_resolution_clock::now();
            int x= BinarySearch( v[randNum], low,  high);
            sum_of_comparisons+=x;
            outfile<<x<<",";
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            outfile<<duration.count()<<"\n";
            sum+=duration.count();

        }
        cout<<endl<<endl;
        cout<<"avg of time= "<<sum/100<<endl;
        cout<<"avg of comparisons= "<<sum_of_comparisons/100<<endl;

        outfile<<"\n"<<"\n";

        cout<<endl<<endl;

        outfile<<"steps"<<","<<"Time"<<"\n";
        sum=0;
        string a="";
        sum_of_comparisons=0;
        for (int i=0; i<high; i++)
        {
            string a="";
            char randchar;
            int n=rand()%15;
            for (int j=0; j<n; j++)
                a+= randchar = rand()%('a'+'z');
            auto start = high_resolution_clock::now();
            int x= BinarySearch( a, low,  high);
            sum_of_comparisons+=x;
            outfile<<x<<",";
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            outfile<<duration.count()<<"\n";
            sum+=duration.count();
        }
        cout<<endl<<endl;
        cout<<"avg of time of non_existing= "<<sum/100<<endl;
        cout<<"avg of comparisons of non_existing= "<<sum_of_comparisons/100<<endl;
        outfile.close();
    }
};
int main()
{
    searcher a;
    a.load_data(100);
    /* for(int i=0;i<100;i++)
         cout<<a.v[i]<<endl;
    */
    a.test_time_performance("aaron",0,100);

    return 0;
}
