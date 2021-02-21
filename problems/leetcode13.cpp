#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int romanToInt(string s) 
{
    int value = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'M')
        {
            value += 1000;
        }
        if (s[i] == 'D')
        {
            value += 500;
        }
        if (s[i] == 'L')
        {
            value += 50;
        }
        if (s[i] == 'V')
        {
            value += 5;
        }
        if (s[i] == 'I')
        {
            if (i != s.length()-1 && (s[i+1] == 'V'|| s[i+1] == 'X'))
            {
                value--;
            }
            else
            {
                value++;
            }
        }
        if (s[i] == 'X')
        {
            if (i != s.length()-1 &&(s[i+1] == 'L'|| s[i+1] == 'C'))
            {
                value-=10;
            }
            else
            {
                value += 10;
            }
        }
        if (s[i] == 'C')
        {
            if (i != s.length()-1 && (s[i+1] == 'D'|| s[i+1] == 'M'))
            {
                value-=100;
            }
            else
            {
                value += 100;
            }
        }
    }
    return value;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    cout << romanToInt("MCMXCIV");
}