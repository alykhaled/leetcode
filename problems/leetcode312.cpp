#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int dp[101][101][101];

int recurse(vector<int>& nums, int i,int j,int k)
{
    
}

int maxCoins(vector<int>& nums) 
{
    memset(dp,-1,sizeof(dp));

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {3,1,5,8};
    cout << maxCoins(a);
}