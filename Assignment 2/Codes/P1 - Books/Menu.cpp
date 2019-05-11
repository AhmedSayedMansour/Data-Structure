#include "Menu.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}
void Menu::UserMenu()
{
    Book ob;
    while(true)
    {
        cout << "Please enter Your choice : \n\n" << "1- Add book. \n2- Search book by name. \n3-Search book by author."<<
             " \n4-List books in alphabetical order (Ascending). \n5-Update available number of versions of a book "<<
             "\n6-Find the books which have the highest number of versions and print books information.\n \nEnter 0 to exit."<<endl;
        int choice ;
        cin >> choice;
        switch(choice)
        {
        case 0 :
            exit(0);
            break;
        case 1:
            ob.AddBook();
            break;
        case 2:
            ob.Search_By_Name();
            break;
        case 3:
            ob.Search_By_Author_Name();
            break;
        case 4:
            ob.Sort_Books();
            break;
        case 5:
            ob.Update_Avail_Versions();
            break;
        case 6:
            ob.Highest_Avail();
            break;
        default:
            cout << "\nWrong choice, please re-choose a number: \n";
            break;
        }
        cout << "\nPress any key to continue... ";
        getch();
        system("cls");
    }

}
