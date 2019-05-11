#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
struct node
{
    T data;
    node<T> *next;
};

template<class T>
class list
{
private:
    node<T> *head, *tail;
public:

    list()
    {
        head=NULL;
        tail=NULL;
    }

    list(T value, int initial_size){
        node<T> *tmp=new node<T>;
        tmp->data=value;
        tmp->next=NULL;
        head=tmp;
        tail=tmp;
        tmp=NULL;
        for(int i=0;i<initial_size-1;++i){
            node<T> *tmp=new node<T>;
            tmp->data=value;
            tmp->next=NULL;
            tail->next=tmp;
            tail=tmp;
        }
    }

    list<T>& operator = (list<T> another_list){
        if( this == &another_list )
            return *this;
        iterator itr =another_list.begin( );
        this->push_back(*itr);
        do{
            ++itr;
            this->push_back(*itr);
        }while(itr != another_list.end());
        return *this;
    }

    class iterator {
    public:
        node<T> *nodeite;
        node<T> *headite;
    public:
        iterator(){
            nodeite=nullptr;
            headite=nullptr;
        }
        iterator(node<T> *Ptrnode,node<T> *h){
            nodeite=Ptrnode;
            headite=h;
        }

        void operator++() {
            if (nodeite->next == NULL ){
                cout << "\nOut of Range\n";
                return;
            }
            nodeite = nodeite->next;
        }

        void operator -- (){
            list<T>:: iterator i;
            i.nodeite=this->headite;
            i.headite=this->headite;
            if (this->headite == this->nodeite ){
                cout<<"\nOut of Range\n";
            }
            else {
                while (i.nodeite->next != NULL ){
                    if(i.nodeite->next == this->nodeite){
                        this->nodeite = i.nodeite;
                        return;
                    }
                    ++i;
                }
            }
        }

        T& operator*() const {
            return nodeite->data;
        }

        bool operator==(const iterator& itr) const {
            return nodeite== itr.nodeite;
        }

        bool operator!=(const iterator& itr) const {
            return nodeite != itr.nodeite;
        }

    };

    iterator erase(iterator position) {
        node<T> *toDelete = position.nodeite->next;
        position.nodeite->next = position.nodeite->next->next;
        if (toDelete == tail) tail = position.nodeite;
        delete toDelete;
        return position;
    }

    void push_back(T value)
    {
        node<T> *temp=new node<T>;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

    void insert(int pos, T value)
    {
        node<T> *pre=new node<T>;
        node<T> *cur=new node<T>;
        node<T> *temp=new node<T>;
        cur=head;
        for(int i=1; i<pos; i++)
        {
            pre=cur;
            cur=cur->next;
        }
        temp->data=value;
        pre->next=temp;
        temp->next=cur;
    }

    void display()
    {
        node<T> *temp=new node<T>;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    void insert_start(T value)
    {
        node<T> *temp=new node<T>;
        temp->data=value;
        temp->next=head;
        head=temp;
    }

    void delete_first()
    {
        node<T> *temp=new node<T>;
        temp=head;
        head=head->next;
        delete temp;
    }

    void delete_last()
    {
        node<T> *current=new node<T>;
        node<T> *previous=new node<T>;
        current=head;
        while(current->next!=NULL)
        {
          previous=current;
          current=current->next;
        }
        tail=previous;
        previous->next=NULL;
        delete current;
    }

    void delete_position(int pos)
    {
        node<T> *current=new node<T>;
        node<T> *previous=new node<T>;
        current=head;
        for(int i=1;i<pos;i++)
        {
          previous=current;
          current=current->next;
        }
        previous->next=current->next;
    }

    bool search(T value){
        node<T> *temp=new node<T>;
        temp=head;
        while(temp!=NULL)
        {
            //cout<<temp->data<<" ";
            if(temp->data == value) return 1;
            temp=temp->next;

        }
        return 0;
        cout<<endl;
    }

    iterator begin() {
      return iterator(head,head);
    }

    iterator end() {
      return iterator(tail,head);
    }

    int size(){
        int count = 0;
        node<T> *temp=new node<T>;
        temp=head;
        while(temp!=NULL)
        {
            ++count;
            temp=temp->next;
        }
        return count;
    }

    ~list(){
        do{
            delete_last();
        }while(head != tail);
        delete head;
        delete tail;
        //cout<<"destructor called"<<endl;
    }

};

int main()
{
    list<int> link(5,2);
    link.push_back(5);
    link.push_back(7);
    link.push_back(8);
    cout<<link.size()<<endl;
    link.display();
    link.insert(2,5);
    link.display();
    link.insert_start(4);
    link.display();
    link.delete_first();
    link.display();
    link.delete_last();
    link.display();
    link.delete_position(2);
    link.display();
    cout<<link.search(5)<<endl;
    cout<<link.search(10);
    cout<<"\n\n\n\n";
    list<int>:: iterator it = link.begin();
    list<int>:: iterator it2 = link.begin();
    cout<<*it;
    ++it;
    cout<<*it;
    ++it;
    cout<<*it;
    ++it;
    cout<<*it;

    ++it;       ///out of range

    --it;
    cout<<*it;
    ++it;
    cout<<*it;

    link.erase(it2);

    cout<<endl;

    list<int> l2;
    l2 = link;
    l2.display();

    return 0;
}
