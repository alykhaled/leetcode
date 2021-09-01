#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int recurse(vector<int>& coins, int amount, vector<int>& dp) 
{
    if (amount < 0) 
    {
        return -1;
    }

    if (amount == 0) 
    {
        return 0;
    }

    if (dp[amount] != 0) 
    {
        return dp[amount];
    }

    int minimum = INT_MAX;
    for (int i : coins) 
    {
        int rem = recurse(coins, amount - i, dp);
        if (rem >= 0) {
            minimum = min(minimum,1 + rem);
        }
    }

    dp[amount] = (minimum == INT_MAX) ? -1 : minimum;

    return dp[amount];
}

int coinChange(vector<int>& coins, int amount) 
{
    vector<int> dp(amount + 1);
    return recurse(coins,amount,dp);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {1,2,5};
    cout << coinChange(a,11);
}