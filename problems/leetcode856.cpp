#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
using namespace std;

int scoreOfParentheses(string s) 
{
    stack<char> st;
    int score = 0, levels = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            levels++;
            st.push(s[i]);
        }
        else if (!st.empty() && s[i] == ')' && st.top() == '(')
        {
            score += pow(2,(levels-1));
            levels--;
            while (!st.empty()) { st.pop(); }     
        }
        else
        {
            levels--;
        }
    }
    return score;
}

int main()
{
    string s = "(()(()))";
    cout << scoreOfParentheses(s);
}
