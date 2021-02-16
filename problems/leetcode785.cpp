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

bool isBipartite(vector<vector<int>>& graph) 
{
    vector<int> verticies(graph.size(),-1);
    for (int j = 0; j < graph.size(); j++)
    {
        queue<int> que;
        que.push(j);
        while (!que.empty())
        {
            int current = que.front();
            que.pop();
            vector<int> currentEdges = graph[current];
            for (int i = 0; i < currentEdges.size(); i++)
            {
                if (verticies[currentEdges[i]] == -1)
                {
                    verticies[currentEdges[i]] = (verticies[current] == 1 ? 2 : 1);
                    que.push(currentEdges[i]);
                }
                else if (verticies[currentEdges[i]] == verticies[current] && verticies[currentEdges[i]] != -1)
                {
                    return false;
                }   
            }
        }
    }
    return true;     
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> graph = {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    cout << (isBipartite(graph) ? "YES" : "NO");
}
