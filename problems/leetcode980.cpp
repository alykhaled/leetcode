#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int paths = 0;
int obstacles = 0;

void dfs(vector<vector<int>>& grid, int x,int y,int walked, vector<vector<bool>> visited)
{
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1 || visited[x][y])
    {
        return;
    }

    if (grid[x][y] == 2)
    {
        if (obstacles == walked - 1)
        {
            paths++;
        }
        visited[x][y] = false;
        return;
    }

    visited[x][y] = true;
    dfs(grid,x+1,y,walked+1,visited);
    dfs(grid,x-1,y,walked+1,visited);
    dfs(grid,x,y+1,walked+1,visited);
    dfs(grid,x,y-1,walked+1,visited);
    visited[x][y] = false;
}

int uniquePathsIII(vector<vector<int>>& grid) 
{
    /*
    1 0 0 0
    0 0 0 0
    0 0 2 -1    
    */
   int startPosX = 0;
   int startPosY = 0;
   int id = 1;
   for (int i = 0; i < grid.size(); i++)
   {
       for (int j = 0; j < grid[0].size(); j++)
       {
           if (grid[i][j] == 1)
           {
               startPosX = i;
               startPosY = j;
           }
           else if(grid[i][j] == 0)
           {
               obstacles++;
           }
       }
   }
   vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
   dfs(grid,startPosX,startPosY,0,visited);
   return paths;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> a = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout << uniquePathsIII(a) <<endl;
}