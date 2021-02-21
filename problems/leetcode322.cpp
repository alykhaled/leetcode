#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;


int recurse(vector<int>&a, int coins, vector<int>& dp, int amount, int current)
{
    if (dp[coins] > amount)
    {
        return 0;
    }
    if (dp[coins] == amount)
    {
        return coins;
    }
    if (dp[coins] != 0)
    {
        return dp[coins];
    }
    for (int i = 0; i < a.size(); i++)
    {
        dp[coins] = min(coins,recurse(a,coins+1,dp,amount,current+a[i]));    
    }
    return dp[coins];
    
}

int coinChange(vector<int>& coins, int amount) 
{
    vector<int> dp(amount,0);
    return recurse(coins,0,dp,amount,0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {1,2,5};
    cout << coinChange(a,11);
}