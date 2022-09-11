#include<iostream>
#include<stack>

using namespace std ;

int main()
{
    
    int arr[] = {50, 30, 20, 40, 10, 45, 5, 60, 8, 15} ;
    int n = 10 ;
    int ans[n] ;

    stack<int> st ;

    for(int i = 0 ; i < n ; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            ans[st.top()] = arr[i] ;
            st.pop() ;
        }

        st.push(i) ;  
    }

    while (!st.empty())
    {
        ans[st.top()] = -1 ;
        st.pop() ;
    }

    for(int i = 0 ; i < n ; i++)
    {
        cout << ans[i] << endl ;
    }

    return  0 ;
}