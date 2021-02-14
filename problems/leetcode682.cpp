#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    vector<string> ops = {"5","2","C","D","+"};
    /*STACK SOLUTION*/
    stack<string> s;
    int sum = 0;
    for (string c : ops)
    {
        if (c == "C")
        {
            s.pop();
        }
        else if (c == "D")
        {
            int score = stoi(s.top());
            score *=2;
            s.push(to_string(score));
        }
        else if (c == "+")
        {
            int a,b;
            b = stoi(s.top());
            s.pop();
            a = stoi(s.top());
            s.push(to_string(b));
            s.push(to_string(a+b));
        }
        else
        {
            s.push(c);   
        }
    }

    while (!s.empty())
    {
        sum += stoi(s.top());
        s.pop();
    }
    cout << sum;
    /*=========================================================*/
    

}