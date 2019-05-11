#include "Book.h"

Book::Book()
{
    //ctor
}

Book::~Book()
{
    //dtor
}
//function to set book name .
void Book::setName(string n)
{
    book_Name = n;
}
//function to set Author name .
void Book::setAuther_Name(string a)
{
    Auther_Name = a;
}
//function to set book publish year .
void Book::setYear(int y)
{
    publish_Year = y;
}
//function to set number of available versions of a book .
void Book::setnum_of_Available_versions(int num)
{
    avail_versions = num;
}
//function to get book name .
string Book::getName()
{
    return book_Name;
}
//function to get Author name .
string Book::getAuther_Name()
{
    return Auther_Name ;
}
//function to get book publish year .
int Book::getYear()
{
    return publish_Year ;
}
//function to get number of available versions of a book .
int Book::getnum_of_Available_versions()
{
    return avail_versions;
}
//Function to add book.
void Book::AddBook()
{
    //Book name from user and put it in container.
    string Bname ;
    cout << "Enter Your Book Name : ";
    cin >> Bname;
    setName(Bname);
    BookNames.push_back(getName()); //vector of book names.

    //Book Author name from user and put it in container.
    string Aname ;
    cout << "Enter Your Book Author Name : ";
    cin >> Aname;
    setAuther_Name(Aname);
    BookAuthorNames.push_back(getAuther_Name());  //vector of book Author names.

    //Book publish year from user and put it in container.
    int year ;
    cout << "Enter Your Book publish year : ";
    cin >> year;
    setYear(year);
    BookPublishYear.push_back(getYear());         //vector of book publish year.

    //Book Author name from user and put it in container.
    int AvailVersions;
    cout << "Enter Your number of Available versions of your book : ";
    cin >> AvailVersions;
    setnum_of_Available_versions(AvailVersions);
    BookAvailVersions.push_back(getnum_of_Available_versions());

}

//Function to print all books.
void Book:: PrintAll()
{
    cout << endl<<endl;
    cout << "Your Books :"<<endl;
    for(unsigned int i = 0 ; i < BookNames.size(); i++)
    {
        cout << "Your book name : "<<BookNames[i]<<endl;
        cout << "Your Book Author Name : "<<BookAuthorNames[i]<<endl;
        cout << "Your Book publish year : "<<BookPublishYear[i]<<endl;
        cout << "Your number of Available versions of your book : "<<BookAvailVersions[i]<<endl;
    }
    cout << endl<<endl;
}
//Function to search for book by (Book Name).
void Book::Search_By_Name()
{
    string Name;
    bool found = false ;
    cout << "Enter the Name of the book you searching for : " ;
    cin >> Name;
    for(unsigned int i = 0 ; i < BookNames.size(); i++)
    {
        if(BookNames[i] == Name)
        {
            found = true;
            cout << "Your book name : "<<BookNames[i]<<endl;
            cout << "Your Book Author Name : "<<BookAuthorNames[i]<<endl;
            cout << "Your Book publish year : "<<BookPublishYear[i]<<endl;
            cout << "Your number of Available versions of your book : "<<BookAvailVersions[i]<<endl;
        }
    }
    if(!found)
    {
        cout << "Not Found !!"<<endl << "The Book you searching for doesn't exist !!"<<endl;
    }
}
//Function to search for book by (Book Author Name).
void Book::Search_By_Author_Name()
{
    string AName;
    bool found = false ;
    cout << "Enter Author Name of the book you searching for : " ;
    cin >> AName;
    for(unsigned int i = 0 ; i < BookAuthorNames.size(); i++)
    {
        if(BookAuthorNames[i] == AName)
        {
            found = true;
            cout << "Your book name : "<<BookNames[i]<<endl;
            cout << "Your Book Author Name : "<<BookAuthorNames[i]<<endl;
            cout << "Your Book publish year : "<<BookPublishYear[i]<<endl;
            cout << "Your number of Available versions of your book : "<<BookAvailVersions[i]<<endl;
        }
    }
    if(!found)
    {
        cout << "Not Found !!"<<endl << "The Book you searching for doesn't exist !!"<<endl;
    }
}

//Function to update number of available versions of a book by (Book Name)
void Book::Update_Avail_Versions()
{
    string Name;
    int num;
    bool found = false ;
    cout << "Enter the Name of the book you want to update its number of available versions : " <<endl;
    cin >> Name;
    cout <<"Enter your new number of available versions :"<<endl;
    cin >> num;
    for(unsigned int i = 0 ; i < BookNames.size(); i++)
    {
        if(BookNames[i] == Name)
        {
            found = true;
            BookAvailVersions[i] = num;
        }
    }
    if(!found)
    {
        cout << "Not Found !!"<<endl << "The Book you wants to update doesn't exist !!"<<endl;
    }
}

//Function to sort Books By Name ascending.
void Book::Sort_Books()
{
    string mini;
    ///Using Insertion Sort.
    for (unsigned int i = 1, j; i < BookNames.size(); i++)
    {
        string tmp_Bname = BookNames [i];
        string tmp_Aname = BookAuthorNames [i];
        int tmp_Avail_versions = BookAvailVersions[i];
        int tmp_pubYear = BookPublishYear [i];
        for (j = i; j > 0 && tmp_Bname < BookNames [j-1]; j--)
        {
            //Swapping the 2 Books.
            BookNames[j] = BookNames[j-1];
            BookAuthorNames[j] = BookAuthorNames[j-1];
            BookAvailVersions [j] = BookAvailVersions [j -1];
            BookPublishYear [j] = BookPublishYear [j -1];
        }
        BookNames [j] = tmp_Bname;
        BookAuthorNames [j] = tmp_Aname;
        BookAvailVersions [j] = tmp_Avail_versions;
        BookPublishYear [j] = tmp_pubYear;
    }
    cout << endl<<endl;
    cout << "Your Books After Sorting :"<<endl;
    for(unsigned int i = 0 ; i < BookNames.size(); i++)
    {
        cout << "Your book name : "<<BookNames[i]<<endl;
        cout << "Your Book Author Name : "<<BookAuthorNames[i]<<endl;
        cout << "Your Book publish year : "<<BookPublishYear[i]<<endl;
        cout << "Your number of Available versions of your book : "<<BookAvailVersions[i]<<endl;
        cout << endl;
    }
    cout << endl<<endl;


}

//Function to Print Books With highest number of available versions.
void Book::Highest_Avail()
{
    int MAX ;
    for(int i = 0 ; i < BookAvailVersions.size()-1; i++)
    {
        MAX = BookAvailVersions[i];
        if( MAX < BookAvailVersions[i+1])
        {
            MAX=BookAvailVersions[i+1] ;
        }
    }
    cout << MAX;
    //Printing
    cout << "\nBook With highest number of available versions : "<<endl;
    for(unsigned int i = 0 ; i < BookAvailVersions.size(); i++)
    {
        if(BookAvailVersions[i] == MAX)
        {
            cout << "Your book name : "<<BookNames[i]<<endl;
            cout << "Your Book Author Name : "<<BookAuthorNames[i]<<endl;
            cout << "Your Book publish year : "<<BookPublishYear[i]<<endl;
            cout << "Your number of Available versions of your book : "<<BookAvailVersions[i]<<endl;
        }
    }
}
