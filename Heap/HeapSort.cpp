#include<iostream>

using namespace std ;

void swap(int arr[], int i , int j)
{
        int temp = arr[i] ;
        arr[i] = arr[j] ;
        arr[j] = temp ;
}

void downheapify(int arr[], int size, int pi)
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
            swap(arr, maxi, pi) ;
            downheapify(arr, size, maxi) ;
        }
}

void heapsort(int arr[] , int n)
{
    // Build Max Heap
    for(int i = n/2 -1 ; i >= 0 ; i--)
    {
        downheapify(arr, n, i) ;
    }

    for(int i = n-1 ; i >= 1 ; i--)
    {
        swap(arr, 0, i) ;
        downheapify(arr, i, 0) ;
    }
}

void display(int arr[], int n)
{
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << "\t" ;
    cout << endl ;
}

int main()
{   
    int arr[] = {12,11,13,5,6,7} ;
    int n = 6 ;

    display(arr,n) ;
    heapsort(arr, n) ;
    display(arr,n) ;

    return 0 ;
}