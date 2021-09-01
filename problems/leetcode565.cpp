#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
    int dfs(int k,unordered_set<int>& set,vector<int>& nums)
    {
        if(set.find(nums[k]) != set.end())
        {
            return set.size();
        }
        else
        {
            set.insert(nums[k]);
            return dfs(nums[k],set,nums) ;
        }
    }
    int arrayNesting(vector<int>& nums) {
        vector<int> res;
        int maxRes = 0;
        //nums[0] = 0; nums[1] = 2; nums[2] = 1
        for(int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> set;
            maxRes = max(maxRes,dfs(i,set,nums));        
        }
        // 
        return maxRes;
    }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> nums = {0,2,1};
    cout << arrayNesting(nums) << endl;
}