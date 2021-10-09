#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

    int checkPath(vector<vector<int>>& grid, vector<vector<int>> visited,int i,int j,int sum)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j] == 1)
        {
            return sum;
        }
        sum += grid[i][j];
        visited[i][j] = 1;
        int top = checkPath(grid,visited,i+1,j,sum);
        int bottom = checkPath(grid,visited,i-1,j,sum);
        int left = checkPath(grid,visited,i,j+1,sum);
        int right = checkPath(grid,visited,i,j-1,sum);
        visited[i][j] = 0;
        return max(top,max(bottom,max(left,right)));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size()));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                ans = max(ans,checkPath(grid,visited,i,j,0));
            }   
        }
        return ans;
    }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    cout << getMaximumGold(grid);
}