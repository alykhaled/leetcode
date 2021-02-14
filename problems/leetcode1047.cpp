#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s = "acdbbdcaf";
    stack<char> m;
    string res = "";
    for (char c : s)
    { 
        if (m.empty() && res.empty())
        {
            m.push(c);
            res +=c;
            continue;        
        }
        if (c == m.top())
        {
            m.pop();
            res.erase(res.end()-1,res.end());
        }
        else
        {
            m.push(c);
            res +=c;
        }   
    }
    cout << res;
}