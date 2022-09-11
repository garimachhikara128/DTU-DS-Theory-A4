#include<iostream>
#include<stack>

using namespace std ;


bool parenthesis(string s)
{


    stack<char> st ;

    for(int i = 0 ; i < s.length() ; i++)
    {
        char ch = s[i] ; 

        if(ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch) ;
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            // it checks if you have seen a closing bracket before an opening bracket
            if(st.empty())
            {
                return false ;
            }
            else if(ch == ')' && st.top() == '(')
            {
                st.pop() ;
            }
            else if(ch == ']' && st.top() == '[')
            {
                st.pop() ;
            }
            else if(ch == '}' && st.top() == '{')
            {
                st.pop() ;
            }
            // if you dont get corresponding pair
            else
            {
                return false ;
            }
        }
    }

    return st.empty() ;
}

int main()
{

    string s = "[{}]}" ;
   cout <<  parenthesis(s) ;

    return 0 ; 
}