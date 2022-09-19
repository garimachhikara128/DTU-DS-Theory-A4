#include<iostream>

using namespace std ;

class Stack
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
    Node *tail = NULL ;

    public :


    int peek()
    {
        if(head == NULL)
        {
            cout << "LL is empty." ;
            return INT_MIN ;
        }

        return head -> data ;
    }

    void push(int item)
    {
        // create a new node
        Node *nn = new Node(item) ;

        if(head == NULL)
        {
            head = nn ;
            tail = nn ;
        }
        else
        {
            // linking
            nn->next = head ;

            // updation of data members
            head = nn ;
        }
    
    }

    int pop()
    {
        // store
        Node *temp = head ;
        int tdata = temp->data ;

        // size() == 1 
        // head->next == NULL
        if(head == tail)
        {
            // deallocate memory
            delete temp ;

            head = NULL ;
            tail = NULL ;
        }
        else
        {
            // links
            Node *newstart = head->next ;
            temp->next = NULL ;

            // deallocate memory
            delete temp ;

            // data members
            head = newstart;

        }

        return tdata ;
    }

} ;
int main()
{
    Stack s ;

    s.push(10) ;
    s.push(20) ;
    s.push(30) ;

    cout << s.pop() ;

}