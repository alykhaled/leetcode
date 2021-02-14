#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s = ")()(())";
    stack<char> m;
    int valid = 0;
    int maxv = 0;
    for (char c : s)
    {
        if (m.empty())
        {
            m.push(c);
            continue;

        }
        if (c == ')' && m.top() == '(')
        {
            m.pop();
            valid += 2;
            maxv = max(maxv,valid);
        }
        else if(valid == 0)
        {
            valid = 0;
            m.push(c);
        }
    }
    cout << maxv;
}

/*

({[(]})

*/