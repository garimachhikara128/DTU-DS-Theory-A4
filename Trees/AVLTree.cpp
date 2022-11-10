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

    void display()
    {
        display(root) ;
    }

    void remove(int item)
    {     
        root = remove(item, root) ;
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


        node->ht = max(height(node->left) , height(node->right)) + 1 ;

        int bf = balancingfactor(node) ;

        // bf violated -> rotation

        // LL case
        if(bf > 1 && item < node->left->data)
        {
            return rightrotation(node) ;
        }

        // RR Case
        if(bf < -1 && item > node->right->data)
        {
            return leftRotation(node) ;
        }

        // LR Case
        if(bf > 1 && item > node->left->data)
        {
            node->left = leftRotation(node->left) ;
            return rightrotation(node) ;
        }

        // RL Case
        if(bf < -1 && item < node->right->data)
        {
            node->right = rightrotation(node->right) ;
            return leftRotation(node) ;

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

    Node *leftRotation(Node *c)
    {
        // capture
        Node *b = c->right ;
        Node *T2 = b->left ;

        // links
        b->left = c ;
        c->right = T2 ;

        // height
        c->ht = max(height(c->left) , height(c->right)) + 1 ;
        b->ht = max(height(b->left) , height(b->right)) + 1 ;

        return b ;

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

    int maximum(Node *node)
    {
        if(node == NULL)
            return INT_MIN ;

        if(node -> right == NULL)
            return node->data ;

        return maximum(node->right) ;
    }

    Node* remove(int item, Node *node)
    {
        if(item < node->data)
            node->left = remove(item, node->left) ;
        else if (item > node->data)
            node->right = remove(item , node->right) ;
        else
        {
            // case 1 
            if(node->left == NULL && node->right == NULL)
            {
                delete node ;
                return NULL ;
            }

            // case 2
            else if(node->left == NULL && node->right != NULL)
            {
                Node *temp = node->right ;
                delete node ;
                return temp ;
            }

            // case 3
            else if(node->left != NULL && node->right == NULL)
            {
                Node *temp = node->left ;
                delete node ;
                return temp ;
            }
            // case 4
            else 
            {
                int m = maximum(node->left) ;
                node->left = remove(m, node->left) ;
                node->data = m ;
                return node ;
            }
        }

        // 
        node->ht = max(height(node->left) , height(node->right)) + 1 ;

        int bf = balancingfactor(node) ;

        // LL Case
        if(bf > 1 && balancingfactor(node->left) > 0)
        {
            return rightrotation(node) ;
        }

        // LR Case
        if(bf > 1 && balancingfactor(node->left) < 0)
        {
            return leftRotation(node) ;
        }

        // RR Case
        if(bf < -1 && balancingfactor(node->right) < 0)
        {
            node->left = leftRotation(node->left) ;
            return rightrotation(node) ;
        }

        // LR Case
        if(bf < -1 && balancingfactor(node->right) > 0)
        {
            node->right = rightrotation(node->right) ;
            return leftRotation(node) ;
        }

        return node ;
    }

} ;

int main()
{
    AVLTree bst ;
    bst.add(20) ;
    bst.add(25) ;
    bst.add(30) ;
    bst.add(10) ;
    bst.add(5) ;
    bst.add(15) ;
    bst.add(27) ;
    bst.add(19) ;
    bst.add(16) ;

    bst.display() ;

    return 0 ;
}