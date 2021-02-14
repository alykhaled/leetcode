#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s = "?4:03";
    for (int i = 0; i < 5; i++)
    {
        if (i == 0 && s[i] == '?')
        {
            if (s[i+1] == '9' || s[i+1] == '8' || s[i+1] == '7' ||s[i+1] == '6' ||s[i+1] == '5' ||s[i+1] == '4')
            {
                s[i] = '1';
            }
            else
            {
                s[i] = '2';
            }
        }
        else if (i == 1 && s[i] == '?')
        {
            if (s[i-1] == '2')
            {
                s[i] = '3';
            }
            else
            {
                s[i] = '9';
            }
        }
        else if (i == 3 && s[i] == '?')
        {
            s[i] = '5';
        }
        else if (i == 4 && s[i] == '?')
        {
            s[i] = '9';
        }
        
    }
    cout << s;
    
}