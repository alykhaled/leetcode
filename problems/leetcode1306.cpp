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

/* ======= DFS Solution ===========

void dfs(vector<int>& arr,int index)
{
    if (index >= arr.size() || index < 0 || arr[index] == -1)
    {
        return;
    }
    if(arr[index] == 0)
    {
        can = true;
        return;
    }
    int current = arr[index];
    arr[index] = -1;
    dfs(arr,index+current);
    dfs(arr,index-current);
}
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> arr = {1,1,1,1,1,1,1,1,0};
    int start = 3;
    
    /* ============ BFS Solution =============*/
    bool can = false;
    set<int> visited;
    queue<int> que;
    que.push(start);

    while (!que.empty())
    {
        int current = que.front();
        que.pop();
        if (visited.find(current) ==  visited.end())
        {
            visited.insert(current);
            if (arr[current] == 0)
            {
                can = true;
                break;
            }
            if (current + arr[current] >= 0 && current + arr[current] < arr.size()) {que.push(current + arr[current]);}
            if (current - arr[current] >= 0 && current - arr[current] < arr.size()) {que.push(current - arr[current]);}
        }
        
        
    }

    cout << (can ? "Yes" : "NO");
}