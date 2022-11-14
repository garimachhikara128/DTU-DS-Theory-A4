#include<iostream>

using namespace std ;

class MinHeap
{

    int *arr ;
    int size ;

    public :

    MinHeap(int cap)
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

    int remove()
    {
        swap(0,size-1) ;
        int temp = arr[size-1] ;
        arr[size-1] = 0 ;
        size -- ;

        downheapify(0) ; 

        return temp ;        
    }

    void downheapify(int pi)
    {
        int lci = 2*pi + 1 ;
        int rci = 2*pi + 2 ;

        int mini = pi ;

        if(lci < size && arr[mini] > arr[lci])
            mini = lci ;
        
        if(rci < size && arr[mini] > arr[rci])
            mini = rci ;

        if(mini != pi)
        {
            swap(mini, pi) ;
            downheapify(mini) ;
        }
    }

    int get()
    {
        return arr[0] ;
    }

} ;

int main()
{
    // MinHeap h(20) ;

    // h.add(10) ;
    // h.add(30) ;
    // h.add(20) ;
    // h.add(40) ;
    // h.add(50) ;
    // h.display() ;
    // h.add(5) ;
    // h.display() ;

    // cout << h.remove() << endl;
    // h.display() ;
    // cout << h.remove() << endl;
    // h.display() ;

    int arr[] = {10,5,15,7,40,30,8,50,35,9} ;
    int n = 10 ;
    int k = 5 ;

    MinHeap h(n) ;

    for(int i = 0 ; i < k ; i++)
    {
        h.add(arr[i]) ;
    }

    for(int i = k ; i < n ; i++)
    {
        int weakest = h.get() ;

        if(arr[i] > weakest)
        {
            h.remove() ;
            h.add(arr[i]) ;
        }
    }

    for(int i = 1 ; i <= k ; i++)
        cout << h.remove() << "\t";
    cout << endl ;


    return 0 ;
}