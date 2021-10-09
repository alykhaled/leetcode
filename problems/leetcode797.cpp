#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph, int index, vector<int>& path)
    {
        if(index == 3)
        {
            ans.push_back(path);
            return;
        }
        
        for(int i = 0; i < graph[index].size(); i++)
        {
            path.push_back(graph[index][i]);
            dfs(graph,graph[index][i],path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        path.push_back(0);
        dfs(graph,0,path);
        return ans;
    }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> ans = allPathsSourceTarget(graph);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}