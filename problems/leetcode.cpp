#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) 
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int left = i-1;
        int right = i + 1;
        int sum = 1;
        while (left >= 0 || right <= nums.size()-1)
        {
            if (left >= 0)
            {
                sum *= nums[left];
                left--;
            }
            if (right <= nums.size()-1)
            {
                sum *= nums[right];
                right++;
            }
        }
        ans.push_back(sum);
    }
    return ans;       
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {1,2,3,4};
    vector<int> ans = productExceptSelf(a);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    
}