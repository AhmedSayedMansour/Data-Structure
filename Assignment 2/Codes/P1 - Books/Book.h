#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Book
{
public:
    Book();
    virtual ~Book();
    //container to store book names in.
    vector<string>BookNames;
    //container to store book Author names in.
    vector<string>BookAuthorNames;
    //container to store book publish year in.
    vector<int>BookPublishYear;
    //container to store number of available versions of books  in.
    vector<int>BookAvailVersions;
    //function to set book name .
    void setName(string n);
    //function to set Author name .
    void setAuther_Name(string a) ;
    //function to set book publish year .
    void setYear(int y);
    //function to set number of available versions of a book .
    void setnum_of_Available_versions(int num);
    //function to get book name .
    string getName() ;
    //function to get Author name .
    string getAuther_Name();
    //function to get book publish year .
    int getYear();
    //function to get number of available versions of a book .
    int getnum_of_Available_versions() ;
    //Function to add book.
    void AddBook();
    //Function to print all books.
    void PrintAll();
    //Function to search for book by (Book Name).
    void Search_By_Name();
    //Function to search for book by (Book Author Name).
    void Search_By_Author_Name();
    //Function to update number of available versions of a book by (Book Name).
    void Update_Avail_Versions();
    //Function to sort Books By Name ascending.
    void Sort_Books();
    //Function to Print Books With highest number of available versions.
    void Highest_Avail();

protected:

private:
    string book_Name;
    string Auther_Name;
    int publish_Year;
    int avail_versions;
};

#endif // BOOK_H
