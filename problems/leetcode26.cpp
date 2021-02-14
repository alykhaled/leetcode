#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int removeDuplicates(vector<int>& nums) 
{
    if (nums.size() == 1)
    {
        return 1;
    }
    
    int l = 0,r = 1;
    while(l <= r && r < nums.size())
    {
        if (nums[r] == nums[l])
        {
            nums.erase(nums.begin()+l);
        }
        else
        {
            l++;
            r++;
        }
    }
    return nums.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(a);
}