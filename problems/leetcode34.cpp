#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int goLeft(vector<int>& nums,int left,int target)
{
    if(nums[left] != target)
    {
        return left+1;
    }
    return goLeft(nums,left-1,target);
}
int goRight(vector<int>& nums,int right,int target)
{
    if(nums[right] != target)
    {
        return right-1;
    }
    return goRight(nums,right+1,target);
}
vector<int> bsearch(vector<int>& nums, int target, int left,int right)
{
    int mid = (right+left)/2;
    if(right < left)
    {
        return{-1,-1};
    }
    if(nums[mid] == target)
    {
        vector<int> ans(2);
        ans[0] = goLeft(nums,mid,target);
        ans[1] = goRight(nums,mid,target);
        return ans;
    }
    else if(nums[mid] > target)
    {
        return  bsearch(nums,target,left,mid-1);
    }
    else
    {
        return  bsearch(nums,target,mid+1,right);
    }
}
vector<int> searchRange(vector<int>& nums, int target) {
    return bsearch(nums,target,0,nums.size()-1);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> nums = {1,4};
    int target = 4;
    vector<int> ans = searchRange(nums,target);
    for(int i = 0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}