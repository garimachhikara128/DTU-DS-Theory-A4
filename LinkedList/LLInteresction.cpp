#include<iostream>

using namespace std ;

class LinkedList
{
    class Node
    {
        public :

        int data ;
        Node *next ;

        Node(int data)
        {
            this->data = data ;
            this->next = NULL ;
        }
    } ;

    Node *head = NULL ;

     public :

    void create()
    {
        Node *n1 = new Node(10) ;
        Node *n2 = new Node(20) ;
        Node *n3 = new Node(30) ;
        Node *n4 = new Node(40) ;
        Node *n5 = new Node(50) ;
        Node *n6 = new Node(60) ;
        Node *n7 = new Node(70) ;
        Node *n8 = new Node(80) ;

        n1->next = n2 ;
        n2->next = n3 ;
        n3->next = n4 ;
        n4->next = n5 ;
        n5->next = n6 ;
        n6->next = n7 ;
        n7->next = n8 ;
        n8->next = NULL ;

        head = n1 ;
    }

    bool detectLoop()
    {
        Node *slow = head ;
        Node *fast = head ;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow -> next ;
            fast = fast -> next -> next ;

            if(slow == fast)
            {
                return true ;
            }
        }

        return false ;        

    }

} ;


int main()
{
    LinkedList ll ;
    ll.create() ;
    cout << ll.detectLoop() << endl;

    return 0;
}