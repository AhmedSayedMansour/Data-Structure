/// Title:   Assignment 1 - Assignment 1 - Problem 3
/* programmers: Ahmed Sayed Mansour   20170022
				Fatma Ashraf Ramadan  20170192
				Ibrahim Ramadan Abdou 20170002
*/
/// last edit : 03/03/2019

#include "fraction_calculator.h"
#include "fraction.h"
using namespace std;

fraction_calculator::fraction_calculator()
{
    //ctor
}

void fraction_calculator::begincalculator(){
    cout<<"Ahlan Ya user ya habebe :) "<<endl;
    cout<<"Welcome to fraction calculator :) "<<endl;
    fraction f1,f2;
    cout<<"Enter your first fraction \n";
    cin>>f1;
    cout<<"Enter your second fraction \n";
    cin>>f2;
    int c;
    while(true){
        cout<<"1-Adding\n"<<
        "2-subtracting"<<endl
        <<"3-multiplication"<<endl
        <<"4-dividing"<<endl
        <<"5-exit"<<endl
        <<"choose what U want: ";
        cin>>c;
        if(c==1){
                fraction f3(f1+f2);

                cout<<"f1+f2= "<<f3<<endl;

        }
        else if(c==2){

                fraction f3(f1-f2);
                cout<<"f1-f2= "<<f3<<endl;

        }
        else if(c==3){
                fraction f3(f1*f2);

                cout<<"f1*f2= "<<f3<<endl;

        }
         else if(c==4){
                fraction f3(f1/f2);
                cout<<"f1/f2= "<<f3<<endl;

        }
        else if(c==5){
              cout<<"good bye!"<<endl;
                break;

        }
    }
}
