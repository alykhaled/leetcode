#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    int target = 6;
    int x = 10;
    /*HashMap method O(N)*/
    unordered_map<int,int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]] = i;
    }
    for (int i = 0; i < nums.size()-1; i++)
    {
        if (map.find(target-nums[i+1]) != map.end() && i != map[target-nums[i]])
        {
            cout << i << " " << map[target-nums[i]];
            break;
        }
        
    }

    /* Brute Force approch O(N^2)
    for(int i = 0 ;i < nums.size() ; i++)
    {
        for(int j = i+1 ;j < nums.size() ; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                return {i,j};
            }
        }
    }
    */
    
}