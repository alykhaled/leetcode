#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
using namespace std;

int numFactoredBinaryTrees(vector<int>& arr) 
{
    unordered_map<int,long long> dp;
    set<int> s(arr.begin(),arr.end());
    long long mod = 10e9 + 7;
    for (int i = 0; i < arr.size(); i++)
    {
        dp[arr[i]] = 1;
    }
    for (auto &&i : s)
    {
        for (auto &&j : s)
        {
            if (i % j == 0 && dp.find(i/j) != dp.end())
            {
                dp[i] += dp[j] * dp[i/j];
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += dp[arr[i]];
    }
    return sum % mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {2,4,5,10};
    cout << numFactoredBinaryTrees(a);
}