#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;


int minPath(vector<vector<int>> grid, int i , int j, int m , int n, vector<vector<int>>& dp)
{
    if (i < m && j < n)
    {
        if (i == m - 1 && j == n -1)
        {
            dp[i][j] = grid[i][j];
            return grid[i][j];
        }
        if (dp[i][j] != 0)
        {
            return dp[i][j];
        }
        dp[i][j] = grid[i][j] + min(minPath(grid, i + 1, j, m, n,dp), minPath(grid, i, j + 1, m, n,dp));
        return dp[i][j];
    }
    return INT_MAX;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> grid = { {1,2,3 }, { 4,5,6 }};
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    /*
    
    if m == 1 && j == n then return grid[i][j]
    if i == m-1 && j == n-1 then return min(grid[i][j] + grid[i][j+1] + grid[m][n],grid[i][j] + grid[i+1][j] + grid[m][n] )

    */
    cout << minPath(grid, 0, 0, m, n,dp);
}