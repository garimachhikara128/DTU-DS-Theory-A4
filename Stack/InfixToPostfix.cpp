#include<iostream>
#include<stack>

using namespace std ;

int prec(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 2 ;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1 ;
    }
    else
    {
        return 0 ;
    }

}
int main()
{

    string s = "2+5-3*4" ;

    stack<char> st ;

    string res = "" ;

    for(int i = 0 ; i < s.length() ; i++)
    {
        char ch = s[i] ;

        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            res += ch ;
        }
        else if (ch == '(')
        {
            st.push('(') ;
        }
        else if (ch == ')')
        {
            while(st.top() != '(')
            {
                res += st.top() ;
                st.pop() ;
            }   

            st.pop() ;
        }
        else
        {
            while(!st.empty() && prec(st.top()) >= prec(ch))
            {
                res += st.top() ;
                st.pop() ;
            }
            st.push(ch) ;
        }
    }

    while(!st.empty())
    {
        res += st.top() ;
        st.pop() ;
    }

    cout << res << endl ;

    return 0 ;
}