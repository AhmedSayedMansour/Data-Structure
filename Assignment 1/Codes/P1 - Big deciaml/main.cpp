/// Title:   Assignment 1 - Assignment 1 - Problem 3
/* programmers: Ahmed Sayed Mansour   20170022
				Fatma Ashraf Ramadan  20170192
				Ibrahim Ramadan Abdou 20170002
*/
/// last edit : 03/03/2019


#include <iostream>
#include "bigdecimalint.h"
#include <string>
using namespace std;

int main()
{
    BigDecimalInt num( 3333);
    BigDecimalInt num9(3333);
    cout<<num-num9<<endl;



    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("113456789011345678901134567890");
    BigDecimalInt num3 = num2 + num1;
    BigDecimalInt num4 = num2 - num1;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
//236913578023691357802369135780
    cout << "num2 + num1 = " << num3 << endl;
//10000000001000000000100000000
    cout << "num2 - num1 = " << num4 << endl;
    BigDecimalInt num5("333333333333333333333333333333");
    BigDecimalInt num6("-111111111111111111111111111111");
    BigDecimalInt num7 = num5 + num6;
    BigDecimalInt num8 = num5 - num6;
//222222222222222222222222222222
    cout << "num5 + num6 = " << num7 << endl;
//444444444444444444444444444444
    cout << "num5 - num6 = " << num8 << endl;
    return 0;
}
