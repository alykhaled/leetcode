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
    vector<int> nums = {1,3,2,2,5,2,3,7};
    unordered_map<int,int> map;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
        if (map.count(nums[i]+1))
        {
            ans = max(ans,map[nums[i]] + map[nums[i]+1]);
        }
        if (map.count(nums[i]-1))
        {
            ans = max(ans,map[nums[i]] + map[nums[i]-1]);
        }
    }
    cout << ans;
    
}