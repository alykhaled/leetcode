#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int dp[1001];
int helper(vector<int>& nums,int index, bool last)
{
    if (index >= nums.size())
    {
        return 0;
    }
    
    if (last == (nums[index] - nums[index - 1] > 0))
    {
        return 0;
    }

    dp[index] = (nums[index] - nums[index - 1] > 0);
}

int wiggleMaxLength(vector<int>& nums) 
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {1,7,4,9,2,5};
    cout << wiggleMaxLength(a);
}