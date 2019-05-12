#include "Contact.h"

Contact::Contact(){}

//Setting this contact name.
Contact::Contact(string name)
{
    this->name = name;
}

Contact& Contact::operator = (Contact& rhs){
    name = rhs.name;
    phone_numbers = rhs.phone_numbers;
    return *this;
}

//Function to take phone number.
void Contact::addPhoneNumber(string number)
{
    phone_numbers.addSorted(number);
}

void Contact:: SetName(string n)
{
    this->name = n;
}

//Getter to return contact name.
string Contact::getName()
{
    return name;
}

//returns true if this name less than parameter.
bool Contact::operator<(const Contact & c)
{
    if(this->name < c.name)
        return true;
    else
        return false;
}

//Returns truce if both names are equal.
bool Contact::operator==(const Contact & c)
{
    if(this->name == c.name)
        return true;
    else
        return false;

}
ostream& operator<<(ostream& o, Contact* c)
{
    cout <<endl;
    o << c->name << "\t";
    o << c->phone_numbers;
    return o;
}
