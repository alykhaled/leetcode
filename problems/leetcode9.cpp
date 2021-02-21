#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

bool isPalindrome(int x) 
{
    if(x < 0)
    {
        return false;
    }
    vector<int> digits;
    while (x != 0)
    {
        digits.push_back(x % 10);
        x /= 10;
    }
    for (int i = 0; i < digits.size(); i++)
    {
        if (digits[i] != digits[digits.size()-1-i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    cout << (isPalindrome(1001)?"Yes":"NO");
}