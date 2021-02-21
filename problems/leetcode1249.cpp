#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

string minRemoveToMakeValid(string s) 
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && s[st.top()] == '(')
            {
                st.pop();
            }
            else
            {
            s.erase(s.begin()+i);
                i--;        
            }
        }
    }
    while (!st.empty())
    {
        s.erase(s.begin()+st.top());
        st.pop();
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    cout << minRemoveToMakeValid(")((c)d()(l") <<endl;
    cout << minRemoveToMakeValid(")))t((u)") <<endl;
    cout << minRemoveToMakeValid("))((") <<endl;
    cout << minRemoveToMakeValid("lee(t(c)o)de)") <<endl;
    cout << minRemoveToMakeValid("())()(((") <<endl;
    cout << minRemoveToMakeValid("(a(b(c)d)");
}