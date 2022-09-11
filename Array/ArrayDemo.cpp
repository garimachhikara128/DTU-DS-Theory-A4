#include<iostream>

using namespace std ;

int *fun()
{
    int a[5] ;
    a[0] = 11 ;
    a[1] = 12 ;

    cout << a << endl ; 
    cout << a[0] << endl ; 

    return a ;
}

int main()
{
    int *b = fun() ;

    cout << b << endl ;
    cout << b[0] << endl ;

    return 0 ;
}