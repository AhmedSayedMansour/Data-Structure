#include <iostream>
#include <bits/stdc++.h>
#include <list>

using namespace std;

//Function to remove duplicates.
void removeDup(list<int>&List1)
{
    //Iterator on Merged List.
    list<int>::iterator IT1 = List1.begin();
    //Another iterator on merged list to test if there exists duplicates.
    list<int>::iterator Test = IT1;

     while(++Test != List1.end())
    {
        if(*Test == *IT1)
        {
            List1.erase(Test);  //removing duplicated from merged list.
            Test = IT1;            //when test increased it will be element after IT.
        }
        else
            IT1 = Test; //moving to next element.
    }
}

//Function to Merge two sorted linked list in place.
void MergeSTLlists(list<int>&List1, list<int> List2)
{
    list<int>::iterator IT1 = List1.begin();     //Iterator on first List.
    list<int>::iterator IT2 = List2.begin();     //Iterator on Second List.
    //Looping on List2 and comparing two lists using iterators.
    while(IT2 != List2.end())
    {
        //while List2 element > list1 element -> increase iterator1.
        while(*IT1 < *IT2 && IT1 != List1.end())
            IT1++;
        //List1 element > List2 element then insert list2 element in list1.
        IT1 = List1.insert(IT1, *IT2);  //now IT pointing to inserted element.
        IT2++;
    }
    removeDup(List1); //removing duplicates.
}


int main()
{
    list<int> List1 ;
    list<int> List2;

    List1.push_back(0);
    List1.push_back(5);
    List1.push_back(9);
    List1.push_back(16);
    List1.push_back(200);

    List2.push_back(0);
    List2.push_back(5);
    List2.push_back(17);
    List2.push_back(19);
    List2.push_back(250);



    MergeSTLlists(List1, List2);

    //Iterator to loop on list 1 to print it.
    list<int>::iterator it = List1.begin();

    for(it = List1.begin() ; it != List1.end() ; it++)
    {
        cout << *it << "\t";
    }
    cout << endl;

    return 0;
}
