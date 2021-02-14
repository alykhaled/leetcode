#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

int main()
{
    vector<int> nums = {2,5,4,4,1,3,4,4,1,4,4,1,2,1,2,2,3,2,4,2};
    int k = 3;
    unordered_map<int,int> free;
    int op = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (free.count(k-nums[i]) != 0)
        {
            op++;
            free[k-nums[i]]--;
            if (free[k-nums[i]] == 0)
            {
                free.erase(k-nums[i]);            
            }
        }
        else
        {
            free[nums[i]]++;
        }
    }
    cout << op;
    
    
}