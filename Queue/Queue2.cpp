#include<iostream>

using namespace std ;

class Queue2
{   
    private :

    int total ;
    int *arr ;
    int size ; 
    int front ;
    int rear ;

    public :

    Queue2(int cap)
    {
        total = cap ;
        arr = new int[total] ;
        size = 0 ;
        front = 0 ;
        rear = -1 ;
    }

    Queue2()
    {
        total = 5 ; 
        arr = new int[total] ;
        size = 0 ;
        front = 0 ;
        rear = -1 ;
    }

    void enqueue(int item)
    {
        if(isFull())
        {
            cout << "Queue is Full."  << endl;
            return ;
        }

        rear = (rear + 1)%total ;
        arr[rear] = item ;
        size ++ ;
    }

    int dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty."  << endl;
            return INT_MIN;
        }

        int temp = arr[front] ;

        arr[front] = 0 ;
        front = (front + 1) % total;
        size -- ;

        return temp ;
    }

    int getFront()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty."  << endl;
            return INT_MIN;
        }

        int temp = arr[front] ;
        return temp ;
    }

    bool isEmpty()
    {
        return size == 0 ;
    }

    bool isFull()
    {
        return size == total ;
    }

    void display()
    {
        cout << "-------------------" << endl ;
        for(int i = 0 ; i < size ; i++)
        {
            int idx = (i + front) % total ;
            cout << arr[idx] << endl;
        }
        cout << "-------------------" << endl ;
    }

} ;

int main()
{

    Queue2 q (5) ;

    q.enqueue(10) ;
    q.enqueue(20) ;
    q.enqueue(30) ;
    q.enqueue(40) ;
    q.enqueue(50) ;

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.enqueue(60) ;
    q.enqueue(70) ;

    q.display() ;

    q.enqueue(80) ;

    return 0 ;
}

