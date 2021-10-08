#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> res(nums.size());
        int pos = nums.size()-1;
        while(left < right)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                res[pos] = abs(nums[left]*nums[left]);
                left++;
            }
            else{
                res[pos] = abs(nums[right]*nums[right]);
                right--;
            }
            pos--;
        }
        return res;
    }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> nums = {-7,-3,2,3,11};
    vector<int> res = sortedSquares(nums);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}