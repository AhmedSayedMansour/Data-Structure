/// Title:   Assignment 1 - Assignment 1 - Problem 3
/* programmers: Ahmed Sayed Mansour   20170022
				Fatma Ashraf Ramadan  20170192
				Ibrahim Ramadan Abdou 20170002
*/
/// last edit : 03/03/2019
/// Version: 3.0

#include "matrix.h"
#include <conio.h>

class Menu
{
    public:
        Menu();
        virtual ~Menu();
        template<class T>
        void printMenu(matrix<T>& ob);
    protected:
    private:
};

template<class T>
void Menu::printMenu(matrix<T>& ob)
{
    cout << "Welcome to your Matrix Calculator"<<endl;
    cout << "----------------------------------------"<<endl;
    matrix <T>mat2,mat3;
    int mode;
    bool con=true;
    while(con)
    {
        cout << "1- Perform Matrix Addition"<<"\n2- Perform Matrix Subtraction."
             <<"\n3- Perform Matrix Multiplication."<<"\n4- Matrix Transpose."
             "\n5- Enter 0 to Exit."<<endl;
        cin >> mode;
        switch(mode)
        {
        case 0:
            con=false;
            break;
        case 1:
            cout << "Enter Your First Matrix : ";
            cin >> ob;
            cout << "Enter Your Second Matrix : ";
            cin>>mat2;
            if(ob.getrow()==mat2.getrow() && ob.getcol()==mat2.getcol()){
                mat3 = ob + mat2;
                cout <<"\nMatrix 1 + Matrix 2 = "<< mat3<<endl;
            }
            else    cout<<"\nOOPS :( \nRows and Columns are not equal\n";
            break;
        case 2:
            cout << "Enter Your First Matrix : ";
            cin >> ob;
            cout << "Enter Your Second Matrix : ";
            cin>>mat2;
            if(ob.getrow()==mat2.getrow() && ob.getcol()==mat2.getcol()){
                mat3 = ob - mat2;
                cout <<"\nMatrix 1 - Matrix 2 = "<< mat3;
            }
            else    cout<<"\nOOPS :( \nRows and Columns are not equal\n";
            break;
        case 3:
            cout << "Enter Your First Matrix : ";
            cin >> ob;
            cout << "Enter Your Second Matrix : ";
            cin>>mat2;
            if(ob.getcol()==mat2.getrow()){
                cout <<"\nMatrix 1 * Matrix 2 = "<< (ob*mat2);
            }
            else    cout<<"\nOOPS :( \nRows and Columns are not equal\n";
            break;
        case 4:
            cout << "Enter Your Matrix : ";
            cin >> ob;
            cout << "transposed Matrix : " << endl;
            cout << transpose(ob) << endl << endl;
            break;
        default:
            continue;
        }
    }

    cout << "\nPress any key to continue... ";
    getch();
    system("cls");
}
