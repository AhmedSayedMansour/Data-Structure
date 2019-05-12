#ifndef CONTACT_H_
#define CONTACT_H_

#include "LinkedList.h"

class Contact {
private:
	string name;
	LinkedList<string> phone_numbers;
public:
	Contact();
	Contact& operator = (Contact& rhs);
	Contact(string name);
	void addPhoneNumber(string number);
	string getName();
	void SetName(string n);
	bool operator<(const Contact & c);
	bool operator==(const Contact & c);
	friend ostream& operator<<(ostream& o, Contact* c);
};

#endif  /* CONTACT_H_ */
