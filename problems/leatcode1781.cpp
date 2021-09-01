#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int beautySum(string s) 
{
    unordered_map<char,int> map;
    int maxL = INT_MIN;
    int minL = INT_MAX;
    int sum = 0;
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = i; j < s.length(); j++)
        {
            map[s[j]]++;
            maxL = max(maxL, map[s[j]]);
            if (map[s[j]] > maxL)
            {
                maxL = 
            }
            
            if (j >= i+2)
            {
                minL = min(minL, map[s[j]]);
                sum += (maxL - minL);
            }
        }
        map.clear();
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    cout << beautySum("aabcb");
}