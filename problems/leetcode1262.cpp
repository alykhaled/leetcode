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
int maxSum(vector<int> a,int index)
{
    if (dp.find(index) == dp.end())
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
    return 0;
}

int main()
{
    vector<int> nums = {3,6,5,1,8};
    // for (int i = 0; i < count; i++)
    // {
    //     /* code */
    // }
    
}