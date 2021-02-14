#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int minPath(vector<vector<int>>& grid,int i,int j, int m ,int n,vector<vector<int>>& dp)
{
    if (i < m && j < n)
    {
        if (grid[i][j] != 1)
        {
            if (dp[i][j] != 0)
            {
                return dp[i][j];
            }
            if (i == m-1 && j == n-1)
            {
                return 1;
            }
            dp[i][j] = minPath(grid,i+1,j,m,n,dp) + minPath(grid,i,j+1,m,n,dp);
            return dp[i][j];
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> obstacleGrid = {{0,1},{0,0}};
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n));
    cout << minPath(obstacleGrid,0,0,m,n,dp);
}