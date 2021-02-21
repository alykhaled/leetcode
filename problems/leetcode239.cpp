#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    int maxS = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        maxS = max(maxS,nums[i]);
    }
    vector<int> a;
    a.push_back(maxS);
    int l = 0, r= k-1;
    while (l < r && r < nums.size())
    {
        maxS = max(maxS,nums[r]);
        r++;
        a.push_back(maxS);
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {1,3,-1,-3,5,3,6,7};
    vector<int> ans = maxSlidingWindow(a,3);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
}
