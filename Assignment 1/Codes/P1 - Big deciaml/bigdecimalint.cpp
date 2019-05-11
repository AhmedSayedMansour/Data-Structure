/// Title:   Assignment 1 - Assignment 1 - Problem 3
/* programmers: Ahmed Sayed Mansour   20170022
				Fatma Ashraf Ramadan  20170192
				Ibrahim Ramadan Abdou 20170002
*/
/// last edit : 03/03/2019

#include "bigdecimalint.h"
#include <iostream>
#include <string>
using namespace std;

//making a function to reverse string
void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}



//making the constructors of the class

BigDecimalInt::BigDecimalInt()
{
    num="";
}


BigDecimalInt::BigDecimalInt(string decstr)
{
    num=decstr;
}

BigDecimalInt :: BigDecimalInt (int decint)
{
    if (decint < 0)
    {
        decint*=-1;

        while ( decint!=0)
    {

        num+=(decint%10)+'0';
        decint-= decint%10;
        decint/=10;

    }
    num+='-';
    }



 else   if (decint == 0)
    {
        //cout<<"i'm here\n";
        num="0";
    }


else if (decint >0 ){
    while ( decint!=0)
    {

        num+=(decint%10)+'0';
        decint-= decint%10;
        decint/=10;

    }
}
    reverseStr(num);

}


// function for printing the class

ostream& operator<< (ostream& output, BigDecimalInt a)
{
    cout<<a.num;
}


//function to delete left zeros

void removeleftzeros(string &a)
{
    if (a[0]=='0')
    {
        int i=0;
        while (a[i]=='0')
            i++;

        if (i==(a.length()))
            a.erase(0,i-1);
       else
            a.erase(0,i);
    }

   else if (a[0]=='-'&&a[1]=='0')
    {
       int i=0;
       while (a[i+1]=='0')
            i++;
        if (i==a.length())
            a.erase(1,i-1);
       else
            a.erase(1,i);
    }
}

//function to check valid of the num

bool checkvalid(BigDecimalInt &b)
{
    if (b.num[0]!='+'&&b.num[0]!='-'&&b.num[0]>'9'&&b.num[0]<'0')
    {
        return 0;
    }
    for (int i=1; i<b.num.length(); i++)
    {
        if (b.num[i]>'9'&&b.num[i]<'0')
        {
            return 0;
        }
    }
    return 1;
}

//function to check sign of class
bool checksign(BigDecimalInt &b)
{
    string c="";
    if (b.num[0]=='-')
    {
        for (int i=1; i<b.num.length(); i++)
        {
            c+=b.num[i];
        }
        b.num=c;
        return 1;
    }

    else if(b.num[0]=='+')
    {

        for (int i=1; i<b.num.length(); i++)
        {
            c+=b.num[i];
        }
        b.num=c;
        return 0;

    }
    else
    {
        return 0;
    }


}

//check which class is bigger

bool checkbigger(string a, string b)
{
    if (a.length()==b.length())
    {
        for (int i=0; i<a.length(); i++)
        {
            if (a[i]>b[i])
            {

                return 1;
            }
            else if (b[i]>a[i])
            {

                return 0;
            }
        }

    }

}




//function to check equality

bool checkequality(string a, string b)
{

    for (int i=0;i<a.length();i++)
    {
        if (a[i]==b[i])
        {
            continue;
        }
        else
            return 0;

    }

    return 1;
}


BigDecimalInt BigDecimalInt::operator+(BigDecimalInt b)
{

   if (  num[0]=='-'   &&  (b.num[0]=='+'||(b.num[0]<='9'&&b.num[0]>='0'))  )


    {
        checksign(*this);
        return b - *this;
    }

    if ((num[0]=='+'||(num[0]<='9'&&num[0]>='0'))       &&      b.num[0]=='-')
    {
        checksign(b);
        return *this - b;
    }


    if (b.num.length()>num.length())
    {

        bool checker = (checksign(b)&&checksign(*this)); /// if both - add - at the end

        int diff=b.num.length()-num.length();

        BigDecimalInt c;
        c.num="";
        c.carry=0;

        for (int i=(num.length()-1); i>=0; i--)
        {

            c.sum=0;
            c.sum=num[i]+b.num[i+diff]-2*'0'+c.carry;
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';

        }
        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=b.num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;

            }

            c.num+=c.sum+'0';
        }
        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }

        if (checker)
        {
            c.num+='-';
        }
        reverseStr(c.num) ;
        return c;

    }


    else if (num.length()>b.num.length())
    {

        bool checker=checksign(b)&&checksign(*this);
        int diff=num.length()-b.num.length();
        BigDecimalInt c;
        c.num="";
        c.carry=0;

        for (int i=(b.num.length()-1); i>=0; i--)
        {
            c.sum=0;
            c.sum=num[i+diff]+b.num[i]-2*'0'+c.carry;
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';

        }
        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;

            }
            c.num+=c.sum+'0';

        }

        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }

        if (checker)
        {
            c.num+='-';
        }
        reverseStr(c.num) ;
        return c;
    }


    else
    {

        bool checker=checksign(b)&&checksign(*this);

        BigDecimalInt c;
        c.num="";
        c.carry=0;

        for (int i=(num.length()-1); i>=0; i--)
        {

            c.sum=0;
            c.sum=num[i]+b.num[i]-2*'0'+c.carry;
            c.carry=0;
            if (c.sum>9)
            {
                c.sum-=10;
                c.carry++;
            }
            c.num+=c.sum+'0';

        }

        if (c.carry>0)
        {
            c.num+=c.carry+'0';
        }

        if (checker)
        {
            c.num+='-';
        }


        reverseStr(c.num) ;
        return c;

    }
}



BigDecimalInt BigDecimalInt::    operator-(BigDecimalInt b)
{
    if (b.num[0]=='-'    &&        (num[0]=='+'||(num[0]<='9'&&num[0]>='0')))
    {
        checksign(b);
        return *this+b;
    }


    else if (num[0]=='-'    &&      (b.num[0]=='+'||(b.num[0]<='9'&&b.num[0]>='0')))
    {

        checksign(*this);
        return *this + b;

    }

    else if (b.num[0]=='-'&&num[0]=='-')
    {
        checksign(b);
        checksign(*this);
        return b- *this;
    }


    if (num.length()>b.num.length())
    {

        int diff = num.length()-b.num.length();
        BigDecimalInt c;
        c.num="";
        c.carry=0;
        for (int i=(b.num.length()-1); i>=0; i--)
        {


            c.sum=0;
            c.sum=num[i+diff]-b.num[i]+c.carry;
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }
            c.num+=c.sum+'0';


        }

        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }

            c.num+=c.sum+'0';
        }

        reverseStr(c.num);

        removeleftzeros(c.num);
        return c;




    }




    if (b.num.length()>num.length())
    {

        int diff =b.num.length()-num.length();
        BigDecimalInt c;
        c.num="";
        c.carry=0;
        for (int i=(num.length()-1); i>=0; i--)
        {


            c.sum=0;
            c.sum=b.num[i+diff]-num[i]+c.carry;
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }
            c.num+=c.sum+'0';


        }

        for (int i=diff-1; i>=0; i--)
        {
            c.sum=0;
            c.sum+=b.num[i]+c.carry-'0';
            c.carry=0;
            if (c.sum<0)
            {
                c.sum+=10;
                c.carry--;
            }
            c.num+=c.sum+'0';
        }

        c.num+='-';

        reverseStr(c.num);
        removeleftzeros(c.num);

        return c;




    }

    if (num.length()==b.num.length())
    {
        if (checkequality(num,b.num))
        {
            BigDecimalInt c;
            c.num="0";
            return c;
        }

        if (checkbigger(num,b.num))
        {



            BigDecimalInt c;
            c.num="";
            c.carry=0;
            for (int i=(num.length()-1); i>=0; i--)
            {


                c.sum=0;
                c.sum=num[i]-b.num[i]+c.carry;
                c.carry=0;
                if (c.sum<0)
                {
                    c.sum+=10;
                    c.carry--;
                }
                c.num+=c.sum+'0';


            }


            reverseStr(c.num) ;

           removeleftzeros(c.num);
            return c;
        }

        else if (checkbigger(b.num,num))
        {

            BigDecimalInt c;
            c.num="";
            c.carry=0;
            for (int i=(b.num.length()-1); i>=0; i--)
            {
                c.sum=0;
                c.sum=b.num[i]-num[i]+c.carry;
                c.carry=0;
                if (c.sum<0)
                {
                    c.sum+=10;
                    c.carry--;
                }
                c.num+=c.sum+'0';
            }
            c.num+='-';
            reverseStr(c.num) ;
            removeleftzeros(c.num);

            return c;
        }
    }
}

int BigDecimalInt ::size()
{
    return num.length();
}




