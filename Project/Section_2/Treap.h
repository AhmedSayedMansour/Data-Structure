#ifndef TREAP_H_
#define TREAP_H_
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template<class T, class V>
class Treap {
public:
	class Node {
	public:
		Node *left, *right;
		T key;              //Will be used as the phone number
		V value;            //considered as the contact
		int priority;       //Random number

		Node(T k, V v)
		{
            key = k;
            value = v;
            priority = rand()%100;
            left = right = NULL;
		}

		friend void printinorder(Treap<T, V>::Node* root){
            if (root){
                printinorder(root->left);
                cout << root->value << endl;
                printinorder(root->right);
            }
        }

		friend ostream& operator<<(ostream &o, Treap<T, V>::Node* root){
            printinorder(root);
            return o;
		}
	};
private:
	Node* root;

	/* Recursive implementation of insertion in Treap */

	Node* rotateRight(Node* Q){
        Node *x = Q->left,  *T2 = x->right;

        // Perform rotation
        x->right = Q;
        Q->left = T2;

        // Return new root
        return x;
	}
	Node* rotateLeft(Node* p){
        Node *y = p->right, *T2 = y->left;

        // Perform rotation
        y->left = p;
        p->right = T2;

        // Return new root
        return y;
	}

	//Node* balance(Node* r); //cared about the balancing in the insertion :)

	Node* insert(Node* r, T k, V v){
        // If root is NULL, create a new node and return it
        if (r == NULL){
            Node* temp = new Node(k,v);
            return temp;
        }

        // If key is smaller than root
        if (k <= r->key)
        {
            // Insert in left subtree
            r->left = insert(r->left, k ,v);

            // Fix Heap property if it is violated
            if (r->left->priority > r->priority)
                r = rotateRight(r);
        }
        else  // If key is greater
        {
            // Insert in right subtree
            r->right = insert(r->right, k ,v);

            // Fix Heap property if it is violated
            if (r->right->priority > r->priority)
                r = rotateLeft(r);
        }
        return r;
	}

	V find(Node* r, T k){   //considered returning phone number
        // Base Cases: root is null or key is present at root
        if ( r == NULL)
           return 0;

        else if (r->key == k )
           return r->value;

        // Key is greater than root's key
        if (r->key < k)
           return find(r->right, k);

        // Key is smaller than root's key
        return find(r->left, k);
    }
public:
	Treap(){
        root = NULL;
	}
	void insert(T k, V v){
        root=insert(root , k , v);
    }
	V find(T k){
        return find(root , k);
	}
	friend ostream& operator<<(ostream &out, Treap<T, V> tree){
        out<<tree.root;
        return out;
	}
};

#endif /* TREAP_H_ */
