/// Title:   Assignment 1 - Assignment 1 - Problem 3
/* programmers: Ahmed Sayed Mansour   20170022
				Fatma Ashraf Ramadan  20170192
				Ibrahim Ramadan Abdou 20170002
*/
/// last edit : 03/03/2019

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;

class fraction
{
    public:
        fraction();
        fraction (int x,int y);
        fraction (const fraction &obj);


        int gcd(int a,int b);
        void reduce();



        bool operator <= (fraction obj);
        bool operator >= (fraction obj);
        bool operator == (fraction obj);
        bool operator != (fraction obj);


        friend istream & operator >> (istream & in , fraction & obj);
        friend ostream & operator << (ostream & out , fraction  obj);

        fraction operator + (fraction  obj);
        fraction operator - (fraction  obj);
        fraction operator * (fraction  obj);
        fraction operator / (fraction  obj);




    protected:
        int num,dum;


};

#endif // FRACTION_H
