#include<iostream>

using namespace std ;

class BinarySearchTree
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

    Node *root ;

    public :
    
    BinarySearchTree()
    {
        this->root = NULL ;
    }

    public :

    void display()
    {
        display(root) ;
    }

    int max()
    {
        return max(root) ;
    }

    bool find(int item)
    {
        return find(root, item) ;
    }

    void add(int item) 
    {
        root = add(root, item) ;
    }

    void remove(int item)
    {
        if(item ==  root->data)
        {
            if(root->left == NULL && root->right == NULL)
                root = NULL ;
            else if(root->left == NULL && root->right != NULL)
                root = root -> right ;
            else if(root->left != NULL && root->right == NULL)
                root = root -> left ;
            else 
                remove(item, root, NULL) ;
        }
        else
            remove(item, root, NULL) ;
    }

    private :

    int max(Node *node)
    {
        if(node == NULL)
            return INT_MIN ;

        if(node -> right == NULL)
            return node->data ;

        return max(node->right) ;
    }

    bool find(Node *node, int item)
    {
        if(node == NULL)
            return false ;

        if(item < node->data)
            return find(node->left, item) ;
        else if (item > node->data)
            return find(node->right, item) ;
        else 
            return true ;
    }

    Node *add(Node *node, int item)
    {
        if(node == NULL)
        {
            Node *nn = new Node(item) ;
            return nn ;
        }

        if(item < node->data)
            node -> left = add(node->left, item) ;
        else if(item > node->data)
            node->right = add(node ->right, item) ;

        return node ;
    }

    void remove(int item, Node *node, Node *parent)
    {
        if(item < node->data)
            remove(item, node->left, node) ;
        else if (item > node->data)
            remove(item , node->right, node) ;
        else
        {
            // case 1 
            if(node->left == NULL && node->right == NULL)
            {
                if(node->data <= parent->data)
                    parent->left = NULL ;
                else
                    parent->right = NULL ;

                delete node ;
            }

            // case 2
            else if(node->left == NULL && node->right != NULL)
            {
                if(node->data <= parent->data)
                    parent->left = node->right ;
                else
                    parent->right = node->right ;

                delete node ;
            }

            // case 3
            else if(node->left != NULL && node->right == NULL)
            {
                if(node->data <= parent->data)
                    parent->left = node->left ;
                else
                    parent->right = node->left ;

                delete node ;
            }

            // case 4
            else 
            {
                int m = max(node->left) ;
                remove(m, node->left, node) ;
                node->data = m ;
            }
        }
    }

    void display(Node *node)
    {
        if(node == NULL)
            return ;

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

        // recursive call for right tree
        display(node->right) ;
       

    }


} ;

int main()
{
    BinarySearchTree bst ;

    bst.add(10) ;
    bst.add(20) ;
    bst.add(30) ;
    bst.add(40) ;
    bst.add(5) ;
    bst.add(2) ;
    bst.add(7) ;
    bst.add(9) ;

    bst.display() ;

    cout << bst.find(19) << endl ;
    cout << bst.max() << endl ;

    bst.remove(10) ;
    bst.display() ;

    return 0 ;
}