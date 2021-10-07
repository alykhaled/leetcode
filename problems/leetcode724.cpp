#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int leftSum = 0,rightSum = 0;
    for(int i = 0; i< nums.size();i++)
    {
        rightSum+=nums[i];
    }
    for(int i = 0; i< nums.size();i++)
    {
        if(rightSum-nums[i] == leftSum)
        {
            return i;
        }
        leftSum += nums[i];
        rightSum -= nums[i];
    }
    return -1;
}        


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout<<pivotIndex(nums);
    return 0;
}