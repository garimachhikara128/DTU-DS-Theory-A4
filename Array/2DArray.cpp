#include<iostream>

using namespace std ;

int main()
{
    int* *arr = new int*[3] ;

    for(int i = 0 ; i < 3 ; i++)
    {
        arr[i] = new int[5] ;
    }

    arr[0][3] = 60 ;

    cout << arr[0][3] ;


    return 0 ;
}