#include "ContactManager.h"

int main()
{
    ContactManager* application = new ContactManager();
    application->loadFromFile("all-contacts.in");
    application->displayNumber("01117908189");
    application->displayNumber("01211009784");
    application->displayNumber("01152395815");
    application->displayNumber("561515181545");

    ///Testing Contact
//    string num , num2 ,num3;
//    Contact *ob  = new Contact("Fatma");
//    Contact *ob2 = new Contact("Ahmed");
//    Contact *ob3 = new Contact("Hema");
//    Contact *ob4 = new Contact("Z");
//    cout << "Enter your number : \n";
//    cin >> num >> num2 >> num3;
//    ob->addPhoneNumber(num);
//    ob->addPhoneNumber(num2);
//    ob->addPhoneNumber(num3);
//    ob2->addPhoneNumber(num);
//    ob2->addPhoneNumber(num2);
//    ob3->addPhoneNumber(num);
//    ob3->addPhoneNumber(num3);
//    ob4->addPhoneNumber(num3);
//    cout << ob;
//    cout << ob2;
//    cout << (ob2 < ob);
//    cout << (ob == ob2);

    ///Testing linked list
//    LinkedList<string> a;
//    string b;
//    for (int i=0;i<4;i++)
//    {
//        cin>>b;
//        a.addSorted(b);
//    }
//    LinkedList<string>::Node* c=a.get("a");
//    cout<<c->value<<endl;
//    cout<<a;

    ///Testing Treap
//    Treap<string,Contact*> tree;
//    tree.insert("Fatma",ob);
//    tree.insert("Ahmed",ob2);
//    tree.insert("Hema",ob3);
//    tree.insert("Z",ob4);
//    cout<<tree;
//    ob=tree.find("fatma");
//    cout<<ob;

    return 0;
}
