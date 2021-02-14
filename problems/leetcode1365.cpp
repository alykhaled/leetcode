#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

int main()
{
    vector<int> nums = {8,1,2,2,3};
    unordered_map<int,int> map;
    vector<int> ans = nums;
    sort(ans.begin(),ans.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.find(ans[i]) == map.end())
        {
            map[ans[i]] = i;
        }     
    }

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = map[nums[i]];
    }
    

}