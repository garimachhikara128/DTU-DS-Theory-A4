#include<iostream>

using namespace std ;

class Stack
{   
    private :

    int total ;
    int *arr ;
    int tos ;

    public :

    Stack(int cap)
    {
        total = cap ;
        arr = new int[total] ;
        tos = -1 ;
    }

    Stack()
    {
        total = 5 ; 
        arr = new int[total] ;
        tos = -1 ;
    }

    // Time : O(1)
    void push(int item)
    {
        if(isFull())
        {
            cout << "Stack is Full."  << endl;
            return ;
        }

        tos++ ;
        arr[tos] = item ;
    }

    // O(1)
    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty."  << endl;
            return INT_MIN;
        }

        int temp = arr[tos] ;
        arr[tos] = 0 ;
        tos -- ;

        return temp ; 
    }

    // O(1)
    int peek()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty."  << endl;
            return INT_MIN;
        }

        int temp = arr[tos] ;
        return temp ;         
    }

    // O(1)
    int size()
    {
        return tos + 1 ;
    }

    // O(1)
    bool isEmpty()
    {
        return size() == 0 ;
    }

    // O(1)
    bool isFull()
    {
        return size() == total ;
    }

    // O(n)
    void display()
    {
        cout << "-------------------" << endl ;
        for(int i = tos ; i >= 0 ;i --)
        {
            cout << arr[i] << endl ;
        }
        // cout << "." << endl ;
        cout << "-------------------" << endl ;

    }  

} ;

void displayReverse(Stack *s)
{
    if(s->isEmpty())
        return ;

    int temp = s->pop() ;
    displayReverse(s) ;
    cout << temp << endl ;
    s->push(temp) ;
}

void actualReverse2(Stack *s, Stack *auxillary)
{
    if(auxillary->isEmpty())
        return ;

    int temp = auxillary->pop() ;
    actualReverse2(s, auxillary) ;
    s->push(temp) ;
}

void actualReverse(Stack *s, Stack *auxillary)
{
    if(s->isEmpty())
    {
        actualReverse2(s, auxillary) ;
        return ;
    }

    int temp = s->pop() ;
    auxillary->push(temp) ;

    actualReverse(s, auxillary) ;
}

int main()
{
    Stack s(10) ;
    Stack extra(10) ;
    
    s.push(10) ;
    s.push(20) ;
    s.push(30) ;
    s.push(40) ;
    s.push(50) ;

    // while(!s.isEmpty())
    // {
    //     cout << s.pop() << endl  ;
    // }

    // displayReverse(&s) ;

    s.display() ;

    actualReverse(&s, &extra) ;

    s.display() ;





}