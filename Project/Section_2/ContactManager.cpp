#include "ContactManager.h"

ContactManager::ContactManager() {}

bool ContactManager::loadFromFile(string fileName)
{
    string number,name;
    fstream file(fileName,ios::in | ios::binary);
    if(!file) return 0;
    file.seekg(0,ios::beg);
    while(!file.eof()){
        getline(file,number,' ');
        getline(file,name,'\n');
        add(name,number);
        file.peek();
    }
    file.close();
    return 1;
}

void ContactManager:: add(string name, string phone_number)
{
    //Adding to linked list.
    Contact *temp = new Contact();
    temp->SetName(name) ;
    temp->addPhoneNumber(phone_number);
    //Adding to treap.
    tree.insert(phone_number , temp);
}

void ContactManager::displayNumber(string phone_number)
{
    Contact *ob = new Contact();
    //searching for this phone number.
    tree.find(phone_number);
    //Printing phone number and
    ob = tree.find(phone_number);
    if(!ob){
        cout<<phone_number<<endl;
        return;
    }
    cout <<ob->getName()<<endl;
}
