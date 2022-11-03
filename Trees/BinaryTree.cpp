#include<iostream>
#include<queue>

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

    BinaryTree(int arr[])
    {
        int i = 0 ;

        queue<Node *> q ;
        root = new Node(arr[i++]) ;
        q.push(root) ;

        while(!q.empty())
        {

            // 1. remove node
            Node *rn = q.front() ;
            q.pop() ;

            // 2. left child 
            int ld = arr[i++] ;
            if(ld != -1)
            {
                Node *leftChild = new Node(ld) ;
                rn->left = leftChild ;
                q.push(leftChild) ;
            }

            // 3. right child
            int rd = arr[i++] ;
            if(rd != -1)
            {
                Node *rightChild = new Node(rd) ;
                rn->right = rightChild ;
                q.push(rightChild) ;
            }
        }

       
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

    void display2()
    {
        display2(root) ;
    }

    void preorder()
    {
        cout << "Preorder \t" ;
        preorder(root) ;
        cout << endl ;
    }

    void inorder()
    {
        cout << "Inorder \t" ;
        inorder(root) ;
        cout << endl ;
    }

    void postorder()
    {
        cout << "Postorder \t" ;
        postorder(root) ;
        cout << endl ;
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

    void display2(Node *node)
    {
        if(node == NULL)
            return ;

        cout << "hii " << node->data << endl ;
        display2(node->left) ;
        cout << "mid " << node->data << endl ;
        display2(node->right) ;
        cout << "bye " << node->data << endl ;

    }

    void preorder(Node *node)
    {
        if(node == NULL)
            return ;

        cout << node->data << "\t" ;
        preorder(node->left) ;
        preorder(node->right) ;

    }

    void inorder(Node *node)
    {
        if(node == NULL)
            return ;
        
        inorder(node->left) ;
        cout << node->data << "\t" ;
        inorder(node->right) ;

    }

    void postorder(Node *node)
    {
        if(node == NULL)
            return ;
        
        postorder(node->left) ;
        postorder(node->right) ;
        cout << node->data << "\t" ;


    }

} ;


int main()
{
    int arr[] = {10,20,30,40,50,-1,60,-1,-1,-1,-1,-1,-1} ;
    BinaryTree bt(arr) ;

    bt.display() ;
    cout << bt.size() << endl;
    cout << bt.ht() << endl ;
    cout << bt.maximum()  << endl ;
    cout << bt.find(-50) << endl ;

    bt.display2() ;

    bt.preorder() ;
    bt.inorder() ;
    bt.postorder() ;

    return 0 ;
}