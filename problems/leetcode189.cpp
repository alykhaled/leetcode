#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
void rotate(vector<int>& nums, int k) {
    vector<int> temp (nums.size());
    if(nums.size() == 1)
    {
        return;
    }
    for(int i = 0; i < nums.size(); i++)
    {
        int index = (i + k) % nums.size();
        temp[index] = nums[i];
    }
    for(int i = 0; i < nums.size(); i++)
    {
        nums[i] = temp[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> nums = {1,2};
    rotate(nums, 3);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}