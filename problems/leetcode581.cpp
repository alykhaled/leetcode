#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
int findUnsortedSubarray(vector<int>& nums) 
{
    vector<int> newarr = nums;
    int l = 0, r = nums.size() - 1;
    int start = -1,end = -1;
    bool firstDiff = true;
    bool lastDiff = true;
    sort(nums.begin(),nums.end());
    while (l <= r && (start == -1 || end == -1))
    {
        if (start == -1)
        {
            if (nums[l] != newarr[l])
            {
                start = l;
            }
            {
                l++;
            }
        }
        if (end == -1)
        {
            if (nums[r] != newarr[r])
            {
                end = r;
            }
            else
            {
                r--;
            }
        }
    }
    return (end - start == 0 ? 0 : end - start + 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {2,6,4,8,10,9,15};
    cout << findUnsortedSubarray(a);
}