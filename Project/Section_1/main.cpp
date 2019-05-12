#include <bits/stdc++.h>
using namespace std;

class word
{
public:
    string key;
    vector <int> index;

    friend ostream& operator <<(ostream & out, word key)
    {
        out<<key.key<<" ";
        for (int i=0; i<key.index.size(); i++)
        {
            if (i==key.index.size()-1)
            {
                out<<key.index[i];
                break;
            }
            out<<key.index[i]<<", ";
        }
        return out;
    }

    bool operator<( word b)
    {
        string c,d;
        for (int i=0; i< key.length() ; ++i)
        {
            c+=tolower(key[i]);
        }
        for (int i=0; i<b.key.length() ; ++i)
        {
            d+=tolower(b.key[i]);
        }
        return (c<d);
    }

    bool operator>( word b)
    {
        string c,d;
        for (int i=0; i< key.length() ; ++i)
        {
            c+=tolower(key[i]);
        }
        for (int i=0; i<b.key.length() ; ++i)
        {
            d+=tolower(b.key[i]);
        }
        return (c>d);
    }

};
//Node class.
template<class T>
class BSTNode
{
public:
    T key;
    BSTNode* right;//greater nodes on right.
    BSTNode* left;//smaller nodes on left.
public:
    //setting initial values to left and right pointers.
    BSTNode()
    {
        right = NULL;
        left = NULL;
    }
    //to be able to send data only as a parameter.
    BSTNode(T DATA, BSTNode* right = 0, BSTNode* left = 0)
    {
        key = DATA;
        this->right = right;
        this->left = left;
    }
    //Getters.
    BSTNode*getleft()
    {
        return left;
    }
    BSTNode*getright()
    {
        return right;
    }
    T getkey()
    {
        return key;
    }
};

//class with all used functions .
template<class T>
class BSTFCI
{
public:
    //Base node in BST.
    BSTNode<T>* root;
public:
    BSTFCI()
    {
        root = NULL;
    }

    BSTFCI(T data)
    {
        root->key = data;
        root->left = root->right = NULL;
    }

    //Recursion Function - Inserting new node to the binary search tree.
    BSTNode<T>* Insert_Node(T DATA, BSTNode<T>* node)
    {
        //InCase there is no node create root node.
        if (node == NULL)
        {
            node = new BSTNode<T>;
            node->key = DATA;
            node->left = node->right = NULL;
        }

        //InCase given key > node key -- > Go right subtree.
        else if (DATA > node->key)
            node->right = Insert_Node(DATA, node->right); //Calling it self.

        //InCase given key < node key -- > Go left subtree.
        else if (DATA < node->key)
            node->left = Insert_Node(DATA, node->left);

        return node;
    }

    //Function to call insert function.
    void Insert(T DATA)
    {
        root = Insert_Node(DATA, root);
    }

    //Printing nodes left then root then right.
    void PrintTreeInOrder(BSTNode<T> * node)
    {
        if (node != NULL)
        {
            PrintTreeInOrder(node->left);
            cout << node->key << endl;
            PrintTreeInOrder(node->right);
        }
    }

    //Function to call PrintTreeInOrder function.
    void PrintTreeInOrder()
    {
        PrintTreeInOrder(root);
        cout << endl<<endl;
    }

    ///Problem#1------------------------------------------------------------------

    //function to calculate the height of each node .
    template<class T2>
    int height(BSTNode<T2>* node);

    //Function returns true if BST balanced.
    template<class T2>
    friend bool isBalanced( BSTNode<T2> *root);


    ///Problem#2------------------------------------------------------------------

    //Recursion Function to check if two subtrees are identical.
    template <typename T2>
    friend bool areIdentical(BSTNode<T2> * root1, BSTNode<T2> * root2);

    template <typename T2>
    friend bool isSubtree(BSTNode<T2> *t, BSTNode<T2> *S);

    template <typename T2>
    friend bool isSubTree(BSTFCI<T2>* t1, BSTFCI<T2>* t2);


    ///Problem#3------------------------------------------------------------------

    //function to print all nodes in the given range.
    template <typename T2>
    friend void PrintRange(BSTNode<T2> *root, int k1, int k2);


    ///Problem#4------------------------------------------------------------------
    //Recursion Function to flip BST.
    void flip(BSTNode<T>* node = BSTFCI<T>::root)
    {
        //node doesn't exist
        if (node == NULL)
            return;

        else
        {
            BSTNode<T>* temp;

            flip(node->left);
            flip(node->right);
            //swapping two nodes using temp.
            temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
    }


    void get_nodes ()
    {
        vector<word>a;

        string s;
        string b="";
        word obj;
        int n;
        cout<<"Enter no. lines: ";
        cin>>n;
        cin.ignore();
        cout<<"Enter your text: "<<endl;
        for (int i=0; i<n; i++)
        {
            getline(cin,s);
            for (int j=0; j<s.length(); j++)
            {
                bool x=0;
                if (s[j]==' '||s[j]=='.'||s[j]==',')
                {
                    x=1;
                    for (int k=0; k<a.size(); k++)
                    {
                        if (a[k].key==b)
                        {
                            a[k].index.push_back(i+1);
                            b="";
                            break;
                        }
                    }
                    if (b!="")
                    {
                        obj.key=b;
                        obj.index.clear();
                        obj.index.push_back(i+1);
                        a.push_back(obj);
                        b="";
                        continue;
                    }

                }

                if (!x)
                    b+=s[j];
                if (j==s.length()-1)
                {
                    for (int k=0; k<a.size(); k++)
                    {
                        if (a[k].key==b)
                        {
                            a[k].index.push_back(i+1);
                            b="";
                            break;
                        }
                    }
                    if (b!="")
                    {
                        obj.key=b;
                        obj.index.clear();
                        obj.index.push_back(i+1);
                        a.push_back(obj);
                        b="";
                        continue;
                    }

                }

            }
        }
        for (int i=0; i<a.size(); i++)
        {
            Insert(a[i]);
        }
    }
};

//function to calculate the height of each node .
template<class T2>
int height(BSTNode<T2>* node)
{
    if(node == NULL)
        return 0;
    //height = 1 + max of left height and right heights
    return 1 + max(height(node->left),height(node->right));
}

//Function returns true if BST balanced.
template<class T2>
bool isBalanced( BSTNode<T2> *root)
{
    int lh; //hight of left subtree.
    int rh; //hight of right subtree.

    if(root == NULL)
        return 1;

    //Hight of left and right subtree.
    lh = height(root->left);
    rh = height(root->right);
    //difference between left and right must be less than or equal to 1.
    if( abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    //tree is not balanced.
    return 0;
}

//Recursion Function to check if two nodes are identical.
template<class T2>
bool areIdentical(BSTNode<T2> * root1, BSTNode<T2> *root2)
{
    if (root1 == NULL && root2 == NULL)     //Both equal NULLs
        return true;

    if (root1 == NULL || root2 == NULL)     //if both nodes are not equal
        return false;

    return (root1->key == root2->key &&                 //check both nodes are equal
            areIdentical(root1->left, root2->left) &&   //check left nodes are equal
            areIdentical(root1->right, root2->right));  //check right nodes are equal
}

//Recursion Function to check if two nodes are identical.
template<class T2>
bool isSubtree(BSTNode<T2> *t, BSTNode<T2> *S)
{
    if (S == NULL)
        return true;

    if (t == NULL)
        return false;

    if (areIdentical(t, S))
        return true;

    return isSubtree(t->left, S) ||
           isSubtree(t->right, S);
}

template<class T2>
bool isSubTree(BSTFCI<T2>* t1, BSTFCI<T2>* t2)
{
    return isSubtree(t1->root, t2->root);
}

//function to print all nodes in the given range.
template <typename T2>
void PrintRange(BSTNode<T2> *root, int k1, int k2)
{
    if ( root == NULL )
        return ;
    // If root->data is greater than k1,then data in left subtree.
    if ( k1 < root->key )
        PrintRange(root->left, k1, k2);
    // if root's data lies in range,then prints root's data .
    if ( k1 <= root->key && k2 >= root->key )
        cout<<root->key<<" ";
    // If root->data is less than k1,then data in right subtree.
    if ( k2 > root->key )
        PrintRange(root->right, k1, k2);
}

int main()
{
    BSTFCI <int> * test1 = new BSTFCI <int>();
    BSTFCI <int> * test2 = new BSTFCI <int>();
    BSTFCI <int> * test3 = new BSTFCI <int>();

    test1->Insert(20);
    test1->Insert(8);
    test1->Insert(22);
    test1->Insert(4);
    test1->Insert(12);
    test1->PrintTreeInOrder();

    test2->Insert(6);
    test2->Insert(7);
    test2->Insert(3);
    test2->Insert(2);
    test2->Insert(5);
    test2->PrintTreeInOrder();

    test3->Insert(5);
    test3->Insert(7);
    test3->Insert(6);
    test3->PrintTreeInOrder();

    PrintRange(test1->root, 10,25);
    cout<<endl;

    if(!isBalanced(test1->root))
        cout <<"\nunBalanced"<< endl<<endl;
    else
        cout <<"\nBalanced"<< endl<<endl;

    if(!isBalanced(test3->root))
        cout <<"\nunBalanced"<< endl<<endl;
    else
        cout <<"\nBalanced"<< endl<<endl;

    cout << isSubTree(test1, test3)<<endl<<endl;

    test2->flip(test2->root);
    test2->PrintTreeInOrder();


    /**
    i am for truth,
    no matter who tells it.
    i am for justice,
    no matter who it is for or against.
    Malcom X
    **/

    BSTFCI <word> * test4 = new BSTFCI <word>();
    test4->get_nodes();
    test4->PrintTreeInOrder();

    return 0;
}
