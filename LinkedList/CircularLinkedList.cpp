#include<iostream>

using namespace std ;

class CircularLinkedList
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

    void display()
    {
        cout << "-------------------" << endl ;

        if(head != NULL)
        {
            Node *temp = head ; 

            do
            {
                cout << temp->data << endl ; 
                temp = temp->next ; 
            }
            while(temp != head) ;
        }

        cout << "-------------------" << endl ;

    }

    int size()
    {
        int count = 0 ;
        
        if(head != NULL)
        {
            Node *temp = head ; 

            do
            {
                count ++ ;
                temp = temp->next ; 
            }
            while(temp != head) ;
        }

        return count ;
    }

    int getFirst()
    {
        if(size() == 0)
        {
            cout << "LL is empty." ;
            return INT_MIN ;
        }

        return head -> data ;
    }

    int getLast()
    {
        if(size() == 0)
        {
            cout << "LL is empty." ;
            return INT_MIN ;
        }

        return tail -> data ;
    }

    int getAt(int idx)
    {
        if(size() == 0)
        {
            cout << "LL is empty." ;
            return INT_MIN ;
        }

        if(idx < 0 || idx >= size())
        {
            cout << "Invalid Index" ;
            return INT_MIN ;
        }

        Node  *temp = head ;
        for(int i = 1 ; i <= idx ; i++)
        {
            temp = temp->next ;
        }

        return temp->data ;
    }

    Node* getNodeAt(int idx)
    {
        if(size() == 0)
        {
            cout << "LL is empty." ;
            return NULL ;
        }

        if(idx < 0 || idx >= size())
        {
            cout << "Invalid Index" ;
            return NULL ;
        }

        Node  *temp = head ;
        for(int i = 1 ; i <= idx ; i++)
        {
            temp = temp->next ;
        }

        return temp ;
    }

    void addLast(int item)
    {
        // create a new node
        Node *nn = new Node(item) ;

        if(head == NULL)
        {
            head = nn ;
            tail = nn ;

            // cll
            tail->next = head ;
        }
        else
        {
            // linking
            tail->next = nn ;

            // updation of data members
            tail = nn ;

            // cll
            tail->next = head ;
        }
    }

    void addFirst(int item)
    {
        // create a new node
        Node *nn = new Node(item) ;

        if(head == NULL)
        {
            head = nn ;
            tail = nn ;

            // cll
            tail->next = head ;
        }
        else
        {
            // linking
            nn->next = head ;

            // updation of data members
            head = nn ;

            // cll
            tail->next = head ;
        }
    
    }

    void addAt(int idx, int item)
    {
        if(idx < 0 || idx > size())
        {
            cout << "Invalid Index" ;
            return  ;
        }

        if(idx == 0)
        {
            addFirst(item) ;
        }
        else if (idx == size())
        {
            addLast(item) ;
        }
        else
        {
            // create
            Node *nn = new Node(item) ;

            // linking
            Node *prev = getNodeAt(idx - 1) ;
            Node *ahead = prev->next ;

            prev->next = nn ;
            nn->next = ahead ;

        }

    }

    int removeLast()
    {
        // store
        Node *temp = tail ;
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
            Node *newlast = getNodeAt(size()-2) ;
            newlast->next = NULL ;

            // deallocate memory
            delete temp ;

            // data members
            tail = newlast ;

            // cll
            tail->next = head ;

        }

        return tdata ;
    }

    int removeFirst()
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

            // cll
            tail->next = head ;

        }

        return tdata ;
    }

    int removeAt(int idx)
    {
        if(idx < 0 || idx >= size())
        {
            cout << "Invalid Index" ;
            return  INT_MIN ;
        }

        if(idx == 0)
        {
            return removeFirst() ;
        }
        else if (idx == size()-1)
        {
            return removeLast() ;
        }
        else
        {

            // store
            Node *prev = getNodeAt(idx-1) ;
            Node *present = prev->next ;
            Node *ahead = present->next ;

            int tdata = present->data ;

            // links
            prev->next = ahead ;

            // delete
            delete present ;

            // data members
            return tdata ;

        }
    }

} ;



int main()
{
    CircularLinkedList ll ;

    ll.addLast(10) ;
    ll.addLast(20) ;
    ll.addLast(30) ;
    ll.addLast(40) ;
    ll.addFirst(50) ;
    ll.addFirst(60) ;
    ll.addAt(0,70) ;
    ll.addAt(ll.size(),80) ;
    ll.addAt(3,100) ;
    ll.display() ;
    cout << ll.removeLast() << endl ;
    ll.display() ;
    cout << ll.removeFirst() << endl ;
    ll.display() ;
    ll.removeAt(3) ;
    ll.display() ;
    

}