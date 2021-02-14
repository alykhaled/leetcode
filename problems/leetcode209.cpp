#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int target = 11;
    vector<int> nums = {1,1,1,1,1,1,1,1};
    int l = 0, r = 0,minl = INT_MAX;
    if(nums.size() == 1)
    {
        return (nums[0] == target ? target : 0);
    }
    int sum = 0;

    while (l <= r && r < nums.size())
    {
        sum += nums[r];

        while (sum >= target)
        {
            minl = min(minl,(r - l + 1));
            sum -= nums[l];
            l++;
        }
        r++;
    }
    if (minl != INT_MAX)
    {
        cout << minl;
    }
    else
    {
        cout << 0;
    }
    
    
    
}