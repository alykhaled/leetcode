#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int n;
unordered_map<int,int> dp;
int robber(vector<int> a,int index)
{
    if (dp.count(index) != 0)
    {
        return dp[index];
    }
    if (index >= n)
    {
        return 0;
    }
    if (index == n-1)
    {
        dp[index] = a[index];
        return a[index];
    }
    dp[index] = a[index];
    dp[index] += max((dp.count(index+2) != 0) ? dp[index+2] : robber(a,index+2),(dp.count(index+3) != 0) ? dp[index+3] : robber(a,index+3));
    return dp[index];
}

int main()
{
    vector<int> nums = {104,209,137,52,158,67,213,86,141,110,151,127,238,147,169,138,240,185,246,225,147,203,83,83,131,227,54,78,165,180,214,151,111,161,233,147,124,143};
    n = nums.size();
    cout << max(robber(nums,0),robber(nums,1));
}