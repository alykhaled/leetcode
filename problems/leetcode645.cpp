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

vector<int> findErrorNums(vector<int>& nums) 
{
    vector<int> numS(nums.size()+1,0);
    int missingNum = 0;
    int repeatedNum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        numS[nums[i]]++;   
    }
    for(int i = 0; i < nums.size(); i++)
    {
        if (numS[nums[i]] == 2)
        {
            repeatedNum = nums[i];
        }
        if (numS[i+1] == 0)
        {
            missingNum = i + 1;
        }
    }
    return {repeatedNum,missingNum};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {1,5,3,2,2,7,6,4,8,9};
    vector<int> ans = findErrorNums(a);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
}