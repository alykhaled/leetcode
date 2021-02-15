#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
#include <cstring>
using namespace std;

int dp[71][71][71];

int recurse(vector<vector<int>>& grid,int i, int j1, int j2)
{
    if (i < 0 || i >= grid.size() || j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size())
    {
        return 0;
    }

    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    
    int maxS = 0;
    maxS  = max(maxS,
            max(recurse(grid,i+1,j1,j2),
            max(recurse(grid,i+1,j1+1,j2),
            max(recurse(grid,i+1,j1-1,j2),
            max(recurse(grid,i+1,j1,j2+1),
            max(recurse(grid,i+1,j1,j2-1),
            max(recurse(grid,i+1,j1+1,j2+1),
            max(recurse(grid,i+1,j1+1,j2-1),
            max(recurse(grid,i+1,j1-1,j2+1),recurse(grid,i+1,j1-1,j2-1))))))))));
    if (j1 == j2)
    {
        maxS += grid[i][j1];
    }
    else
    {
        maxS += grid[i][j1] + grid[i][j2];
    }
    dp[i][j1][j2] = maxS; 
    return dp[i][j1][j2];
}
int cherryPickup(vector<vector<int>>& grid,int k = 0, int i = 0, int j = 0) 
{
    memset(dp,-1,sizeof(dp));

    return recurse(grid,0,0,grid[0].size()-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout << cherryPickup(grid) <<endl;

    /*
    
    3 1 1
    2 5 1
    1 5 5
    2 1 1
    
    */
}