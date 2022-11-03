#include<iostream>

using namespace std ;

class AVLTree
{
    class Node
    {
        public :

        int data ;
        Node *left ;
        Node *right ;
        int ht ;

        Node(int data)
        {
            this->data =  data ;
            this->left = NULL ;
            this->right = NULL ;
            this->ht = 0 ;
        }
    } ;

    Node *root ;

    public :
    
    AVLTree()
    {
        this->root = NULL ;
    }

    void add(int item) 
    {
        root = add(root, item) ;
    }

    private :

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

        int bf = balancingfactor(node) ;

        // bf violated -> rotation

        // LL case
        if(bf > 1 && item < node->left->data)
        {
            return rightrotation(node) ;
        }


        return node ;
    }

    int height(Node *node)
    {
        if(node == NULL)
            return -1 ;
        
        return node->ht ;
    }

    int balancingfactor(Node *node)
    {
        return height(node->left) - height(node->right) ;
    }

    Node * rightrotation(Node *c)
    {
        // captured
        Node *b = c->left ;
        Node *T3 = b->right ;

        // links
        b -> right = c ;
        c -> left = T3 ;

        // height update
        c->ht = max(height(c->left) , height(c->right)) + 1 ;
        b->ht = max(height(b->left) , height(b->right)) + 1 ;

        return b ;
    }


} ;

int main()
{
    AVLTree bst ;

    return 0 ;
}