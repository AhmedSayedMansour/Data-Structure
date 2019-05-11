/*
Problem 2

Programmers:
        Ahmed Sayed Mansour   20170022
        Fatma Ashraf Ramadan  20170192
        Ibrahim Ramadan Abdou 20170002

*/
#include <iostream>
#include<bits/stdc++.h>
#include<map>

using namespace std;

int main()
{
    //Map< key (word) , value (number of occurrence)>.
    map<string,int>CountMap;
    //Iterator to print map.
    map<string,int>::iterator iter;
    //iterator to use in erasing.
    map<string,int>::iterator it;
    string word;
    while(word != "done")
    {
        cin >> word;
        if(word=="done")
            break;
        //Counting the word for the first time.(it doesn't exist in the map.
        if (CountMap.find(word) == CountMap.end())
            //Putting its value with 0.
            CountMap[word] = 1;
        //this word already exits before.
        else
            //only increment its value.
            CountMap[word]++;
    }

    //Printing each word with its number of occurrence.
    cout << "\t"<<"words"<<"\t"<<"Number Of Occurrence"<<endl;
    for(iter = CountMap.begin(); iter != CountMap.end(); iter++)
    {
        cout << "\t"<<iter->first << "\t" << iter->second<<endl;
    }
    //Erasing words begins with 'a'.
    for (auto it = CountMap.cbegin(); it != CountMap.cend(); ) // no "++"!
    {
        if (it->first[0] =='a' )  //testing if each word begins with 'a'.
        {
           CountMap.erase(it++);
        }
        else
        {
            //Moving to next element.
            ++it;
        }
    }

    //Printing After erasing words starts with 'a'.
    cout <<"\t\tAfter Erasing : "<<endl<<endl;
    cout << "\t"<<"words"<<"\t"<<"Number Of Occurrence"<<endl;
    for(iter = CountMap.begin(); iter != CountMap.end(); iter++)
    {
        cout << "\t"<<iter->first << "\t" << iter->second<<endl;
    }


    return 0;
}

