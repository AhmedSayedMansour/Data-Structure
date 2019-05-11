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

void RecPermute(string soFar, string rest)

{

    set<string> arr;
    if (rest == "") // No more characters
        cout << soFar << endl; // Print the word
    else // Still more chars
        // For each remaining char

        for (int i = 0; i < rest.length(); i++) {

            string next = soFar + rest[i]; // Glue next char

            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            int siz=arr.size();
            arr.insert(next);
            if(arr.size()>siz)
            RecPermute(next, remaining);
        }

}

void ListPermutations(string s) {
    RecPermute("", s);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    RecPermute("ahmed","say");
    ListPermutations("abc");
	return 0;
}

