#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s = "(){}}{";
    stack<char> st;
    st.push(s[0]);
    for(int i = 1; i < s.length(); i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
        }
        else if((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    cout << (st.size() == 0);
}
