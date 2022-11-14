#include<iostream>

using namespace std ;

class MaxHeap
{

    int *arr ;
    int size ;

    public :

    MaxHeap(int cap)
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

        if(arr[pi] < arr[ci])
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

        int maxi = pi ;

        if(lci < size && arr[maxi] < arr[lci])
            maxi = lci ;
        
        if(rci < size && arr[maxi] < arr[rci])
            maxi = rci ;

        if(maxi != pi)
        {
            swap(maxi, pi) ;
            downheapify(maxi) ;
        }
    }

    int get()
    {
        return arr[0] ;
    }

} ;

int main()
{
    MaxHeap h(20) ;

    h.add(10) ;
    h.add(30) ;
    h.add(20) ;
    h.add(40) ;
    h.add(50) ;
    h.display() ;
    h.add(5) ;
    h.display() ;

    cout << h.remove() << endl;
    h.display() ;
    cout << h.remove() << endl;
    h.display() ;

    
    return 0 ;
}