#include<iostream>
#include<stack>

using namespace std ;

int main()
{

    string s = "25+34*-" ;

    stack<int> st ;

    for(int i = 0 ; i < s.length() ; i++)
    {
        char ch = s[i] ;

        if(ch >= '0' && ch <= '9')
        {
            st.push(ch - '0') ;
        }
        else
        {
            int e1 = st.top() ;
            st.pop() ;
            int e2 = st.top() ;
            st.pop() ;

            if(ch == '+')
            {
                st.push(e2 + e1) ;
            }
            else if(ch == '-')
            {
                st.push(e2 - e1) ;
            }
            else if(ch == '*')
            {
                st.push(e2 * e1) ;
            }
            else if(ch == '/')
            {
                st.push(e2 / e1) ;
            }
        }
    }

    cout << st.top() ;

    return 0 ;
}

