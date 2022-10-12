#include<iostream>

using namespace std ;

class BinaryTree
{
    class Node
    {
        public :

        int data ;
        Node *left ;
        Node *right ;

        Node(int data)
        {
            this->data =  data ;
            this->left = NULL ;
            this->right = NULL ;
        }
    } ;

    Node *root = NULL ;

    public :

    BinaryTree()
    {
        
        root = new Node(-10) ;
        root->left = new Node(-20) ;
        root->right = new Node(-30) ;
        root->left->left = new Node(-40) ;
        root->left->right = new Node(-50) ;
        root->right->right = new Node(-60) ;
    }

    void display()
    {
        display(root) ;
    }

    int size()
    {
        return size(root) ;        
    }

    int ht()
    {
        return ht(root) ;
    }

    int maximum()
    {
        return maximum(root) ;
    }

    bool find(int item)
    {
        return find(root, item) ;
    }

    private :

    void display(Node *node)
    {
        if(node == NULL)
            return ;

        // recursive call for right tree
        display(node->right) ;

         // print 
        if(node -> left == NULL)
            cout << "." ;
        else
            cout << node->left->data ;

        cout << " -> " << node->data << " <- " ;

        if(node -> right == NULL)
            cout << "." ;
        else
        cout << node->right->data ;

        cout << endl ;

        // recursive call for left tree
        display(node->left) ;

       

    }

    int size(Node *node)
    {
        if(node == NULL)
            return 0 ;

        // left
        int ls = size(node->left) ;

        // right
        int rs = size(node->right) ;

        // work
        return ls + rs + 1 ;
    }

    int ht(Node *node)
    {
        if(node == NULL)
            return -1 ;

        int lh = ht(node->left) ;

        int rh = ht(node->right) ;

        return max(lh, rh) + 1 ;
    }

    int maximum(Node *node)
    {
        if(node == NULL)
            return INT_MIN ;

        int lm = maximum(node->left) ;
        int rm = maximum(node->right) ;

        return max(node->data , max(lm,rm)) ;
    }

    bool find(Node *node, int item)
    {
        if(node == NULL)
            return false ;

        if(node->data == item)
            return true ;

        bool lf = find(node->left, item) ;

        if(lf)
            return true ;
            
        bool rf = find(node->right, item) ;

        return lf || rf ;

    }


} ;


int main()
{
    BinaryTree bt ;
    bt.display() ;
    cout << bt.size() << endl;
    cout << bt.ht() << endl ;
    cout << bt.maximum()  << endl ;
    cout << bt.find(-50) << endl ;

    return 0 ;
}