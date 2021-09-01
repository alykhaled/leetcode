#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <cstring>
#include <stack>
using namespace std;

int dp[50001][2];
int helper(vector<int>& p, int index, bool avaliable, int fee) 
{
    if(index >= p.size())
    {
        return 0;
    }
    
    if(dp[index][avaliable] != -1)
    {
        return dp[index][avaliable];
    }

    if(avaliable)
    {
        dp[index][avaliable] = max(helper(p, index + 1, avaliable,fee), helper(p, index + 1, false,fee) - p[index]);
    } 
    else
    {
        dp[index][avaliable] = max(helper(p, index + 1, avaliable,fee), helper(p, index + 1, true,fee) + p[index] - fee);
    }
    
    return dp[index][avaliable];
}

int maxProfit(vector<int>& prices, int fee) 
{
    memset(dp,-1,sizeof(dp));
    return helper(prices,0,true,fee);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {1,3,2,8,4,9};
    cout << maxProfit(a,2);

}