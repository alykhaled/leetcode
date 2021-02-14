#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n = 15;
    vector<string> s;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0)
        {
            s.push_back("Fizz");
        }
        else if (i%5 ==0)
        {
            s.push_back("Buzz");
        }
        else
        {
            s.push_back(to_string(i));
        }
    }
    
}