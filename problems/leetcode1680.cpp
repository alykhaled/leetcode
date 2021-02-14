#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

string decToBin(int n)
{
    string s ="";
    while (n != 0)
    {
        if (n % 2 == 0)
        {
            s.insert(s.begin(),'0');
        }
        else
        {
            s.insert(s.begin(),'1');

        }
        n /= 2;
    }
    return s;
    
}
int main()
{
    int n = 12;
    long long mod = 1e9 + 7;
    string s = "";
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        s += decToBin(i);
    }
    for (int i = 0; i < s.length() ; i++)
    {
        ans += (long long)((s[s.length()-1-i]-'0') * pow(2,i))% mod;
    }
    
    cout << ans;
    
}