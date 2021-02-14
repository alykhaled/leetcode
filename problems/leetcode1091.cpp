#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int finalmoves = INT_MAX; 
int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
{
    int moves = 0;
    int N = grid.size();
    set<pair<int,int>> visited;
    vector<int> dirX = {0,1,1,1,0,-1,-1,-1};
    vector<int> dirY = {1,1,0,-1,-1,-1,0,1};
    if (grid[0][0] == 1)
    {
        return -1;
    }
    
    queue<pair<pair<int,int>,int>> que;
    que.push({{0,0},1});
    while (!que.empty())
    {
        pair<int,int> current = que.front().first;
        int dist = que.front().second;
        que.pop();
        if (visited.find(current) == visited.end())
        {
            visited.insert(current);
            if (current.second == N - 1 && current.first == N - 1)
            {
                return dist; 
            }
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    int newI = current.first + dirX[i];
                    int newJ = current.second + dirY[j];
                    if ((newI >= 0 && newI < N) && (newJ >= 0 && newJ < N) && grid[newI][newJ] == 0)
                    {
                        que.push({{newI,newJ},dist + 1});
                    }
                }
                // for (int i = -1; i < 2; i++)
                // {
                //     for (int j = -1; j < 2; j++)
                //     {
                //         int newI = current.first + i;
                //         int newJ = current.second + j;
                //         if ((newI >= 0 && newI < N) && (newJ >= 0 && newJ < N) && grid[newI][newJ] == 0)
                //         {

                //             que.push({{newI,newJ},dist + 1});
                //         }
                //     }
                // }
            }
        }
    }
    return -1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> a = {{0,0,0},{1,1,0},{1,1,0}};
    cout << shortestPathBinaryMatrix(a);
}