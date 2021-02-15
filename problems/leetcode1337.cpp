#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
{
    int M = mat.size();
    int N = mat[0].size();
    vector<pair<int,int>> rows;
    for (int i = 0; i < M; i++)
    {
        int soldiers = 0;
        for (int j = 0; j < N; j++)
        {
            if (mat[i][j] == 1)
            {
                soldiers++;
            }
        }
        rows.push_back(make_pair(soldiers,i));
    }
    sort(rows.begin(),rows.end());
    vector<int> ans(k);
    for (int i = 0; i < k; i++)
    {
        ans[i] = rows[i].second;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> mat = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
    vector<int> a = kWeakestRows(mat,3);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }
    
}