/// Title:   Assignment 1 - Assignment 1 - Problem 3
/* programmers: Ahmed Sayed Mansour   20170022
				Fatma Ashraf Ramadan  20170192
				Ibrahim Ramadan Abdou 20170002
*/
/// last edit : 03/03/2019

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <bits/stdc++.h>
#define lp(i, e) for(int i=0; i<e ; i++)
#define lp2(i, f, e) for (int i=f; i<e; i++)
typedef long long int lli;
typedef long long ll;

using namespace std;

int power(int a , int n)
{
    if(n==0)
    {
       return 1;
    }
    return  a* power(a,n-1);
}


int power1(int a , int n)
{
    if (n%2!=0){
        return  power(a,n/2) * power(a,n/2+1);
    }
    else    return   power1(a,n/2) * power1(a,n/2);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<power(5,4)<<endl;
    cout<<power(5,3)<<endl;
    cout<<power1(5,4)<<endl;
    cout<<power1(5,3)<<endl;
	return 0;
}

