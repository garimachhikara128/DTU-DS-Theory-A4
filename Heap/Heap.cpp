#include<iostream>

using namespace std ;

class Heap
{

    int *arr ;
    int size ;

    public :

    Heap(int cap)
    {
        arr = new int[cap] ;
        size = 0 ;
    }

    void add(int item)
    {
        arr[size] = item ;
        size ++ ;

        upheapify(size-1)  ;
    }

    void upheapify(int ci)
    {
        int pi = (ci-1)/2 ;

        if(arr[pi] > arr[ci])
        {
            swap(pi, ci) ;
            upheapify(pi) ;
        }
    }
   
    void swap(int i , int j)
    {
        int temp = arr[i] ;
        arr[i] = arr[j] ;
        arr[j] = temp ;
    }

    void display()
    {
        for(int i = 0 ; i < size ; i++)
        {
            cout << arr[i] << "\t" ;
        }
        cout << endl ;
    }

} ;

int main()
{
    Heap h(20) ;

    h.add(10) ;
    h.add(30) ;
    h.add(20) ;
    h.add(40) ;
    h.add(50) ;
    h.display() ;
    h.add(5) ;
    h.display() ;

    return 0 ;
}