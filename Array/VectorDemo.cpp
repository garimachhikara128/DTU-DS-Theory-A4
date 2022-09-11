#include<iostream>
#include<vector>

using namespace std ;

int main()
{
    vector<int> v ;

    for(int i = 1 ; i <= 20 ; i++)
    {
        cout << v.size() << " , " << v.capacity() << endl ;
        v.push_back(i*10) ;
       
    }

    return 0 ;
}