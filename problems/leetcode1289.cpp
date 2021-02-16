#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
using namespace std;

/*

1 -2 3
4 5 -6
7 8 9

*/

int dp[201][201];
int helper(vector<vector<int>>& arr, int i,int j)
{
    if (i == arr.size()-1)
    {
        return arr[i][j]; 
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int minS = INT_MAX;
    for (int k = 0; k < arr[0].size(); k++)
    {
        if (k != j)
        {
            minS = min(minS,helper(arr,i+1,k)); 
            dp[i][j] = arr[i][j] + minS;    
        }
    }
    return dp[i][j];
}

int minFallingPathSum(vector<vector<int>>& arr) 
{
    memset(dp,-1,sizeof(dp));
    int ans = INT_MAX;
    for (int i = 0; i < arr[0].size(); i++)
    {
        ans = min(ans,helper(arr,0,i));
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> a = {{1,-2,3},{4,5,-6},{7,8,9}};
    cout << minFallingPathSum(a);
}