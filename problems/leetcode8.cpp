#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int myAtoi(string s) {
    int res = 0;
    int units = 1;
    for(int i = s.length() - 1; i >= 0; i--)
    {
        if(s[i] >= 48 && s[i] <= 57)
        {
            int t = s[i] - 48;
            res += units*(t);
            units *= 10;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    string s = "    words and 987";
    char sd = s[2];
    cout << myAtoi(s);
}