#ifndef CONTACT_MANAGER_H_
#define CONTACT_MANAGER_H_

#include"Contact.h"
#include"Treap.h"          // for Task 2

class ContactManager {
private:
	LinkedList<Contact> contacts;   // for task 1
	Treap<string, Contact*> tree;   // for Task 2
public:
	ContactManager();
	bool loadFromFile(string fileName);
	void add(string name, string phone_number);
	void displayNumber(string phone_number);
	friend ostream& operator<<(ostream& o, ContactManager & c);
};

#endif  /* CONTACT_MANAGER_H_ */
