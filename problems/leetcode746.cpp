#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

unordered_map<int,int> dp;
int help(vector<int>& cost, int pos)
{
    if(dp.find(pos) != dp.end())
    {
        return dp[pos];
    }
    if(pos == 0)
    {
        return cost[pos];
    }
    if (pos < 0)
    {
        return 0;
    }
    
    dp[pos] = cost[pos] + min(help(cost,pos-1),help(cost,pos-2));
    return dp[pos];
}
int minCostClimbingStairs(vector<int>& cost) {
    return min(help(cost,cost.size()-1),help(cost,cost.size()-2));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> cost = {10};
    cout << minCostClimbingStairs(cost) << endl;
}