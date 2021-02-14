#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
using namespace std;

int main()
{
    string s = "(())((()))";
    stack<char> m;
    int score = 0;
    int levels = 0;
    bool first = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (m.empty())
        {
            m.push(s[i]);
            continue;
        }
        else if (s[i] == '(')
        {
            levels++;
        }
        else if (s[i] == ')' && m.top() == '(')
        {
            if (levels == 0 || first)
            {
                score += pow(2,levels - 1);
                m.pop();
                for (int i = 0; i < levels -1; i++)
                {
                    m.pop();
                }
            }
            else
            {
                levels--;
            }
            
            first = false;  
        }
        else
        {
            m.push(s[i]);
        }
    }
    
    // for (char c : s)
    // {
    //     if (m.empty())
    //     {
    //         m.push(c);
    //         continue;
    //     }
    //     if (c == ')' && m.top() == '(')
    //     {
    //         score ++;
    //         m.pop();
    //     }
    //     else
    //     {
    //         m.push(c);
    //     }
    // }
    cout << score;
}

/*

(()(()))

(()) 



*/