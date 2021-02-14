#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int uniquePaths(int m, int n,vector<vector<int>>& dp) 
{
    if (m > 0 && n > 0)
    {
        if (dp[m-1][n-1] != 0)
        {
            return dp[m-1][n-1];
        }
        if (m == 1 && n == 1)
        {
            return 1;
        }
        if (m == 0 || n == 0)
        {
            return 0;
        }
        dp[m-1][n-1] = uniquePaths(m-1,n,dp) + uniquePaths(m,n-1,dp);
        return dp[m-1][n-1];
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int m = 3;
    int n = 2;
    vector<vector<int>> dp(m,vector<int>(n));
    cout << uniquePaths(m,n,dp);
}