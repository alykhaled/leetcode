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
unordered_map<int,bool> dp;
bool canSum(int targetSum,vector<int> a)
{
    if (dp.find(targetSum) != dp.end())
    {
        return dp[targetSum];
    }
    if (targetSum == 0)
    {
        dp[targetSum] = true;
        return dp[targetSum];
    }

    for (int i = 0; i < a.size(); i++)
    {
        vector<int> temp = a;
        int reminderpos = targetSum - a[i];
        int reminderneg = targetSum + a[i];
        temp.erase(temp.begin()+i);
        if (canSum(reminderpos,temp) || canSum(reminderneg,temp))
        {
            dp[targetSum] = true;
            return true;
        }
        
    }
    
    dp[targetSum] = false;
    return false;
}

int main()
{
    vector<int> nums = {1,1,1,1,1};
    int S = 4;
    int sum = 0;
    n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> temp = nums;
        int reminderpos = S - nums[i];
        int reminderneg = S + nums[i];
        temp.erase(temp.begin()+i);
        if (canSum(reminderpos,temp) || canSum(reminderneg,temp))
        {
            sum++;
        }
    }
    cout << sum;
}