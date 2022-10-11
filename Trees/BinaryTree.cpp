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
        
        root = new Node(10) ;
        root->left = new Node(20) ;
        root->right = new Node(30) ;
        root->left->left = new Node(40) ;
        root->left->right = new Node(50) ;
        root->right->right = new Node(60) ;
    }

    void display()
    {
        display(root) ;
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

} ;

int main()
{
    BinaryTree bt ;
    bt.display() ;
    return 0 ;
}