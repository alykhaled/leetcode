#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

bool checkPossibility(vector<int>& nums) {
        bool second = false;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(i == nums.size() - 2)
            {
                if(nums[i] > nums[i+1])
                {
                    if(second)
                    {
                        return false;
                    }
                    second = true;
                }
            }
            else if(i != 0 && i != nums.size()-2 && nums[i] > nums[i+1] && nums[i+1] < nums[i-1] && nums[i+1] < nums[i+2])
            {
                if(second)
                {
                    return false;
                }
                else
                {
                    second = true;
                }
                nums[i+1] = nums[i];
            }
            else if(i != 0 && nums[i] > nums[i+1] && nums[i+1] < nums[i-1])
            {
                return false;
            }
            else if(nums[i] > nums[i+1])
            {
                if(second)
                {
                    return false;
                }
                else
                {
                    second = true;
                }
            }
            
        }
        return true;
    }

int main()
{
    vector<int> x = {1,2,4,5,3};
    bool result = checkPossibility(x);
    if(result)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}