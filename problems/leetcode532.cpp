#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int> a,int x)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == x)
        {
            return true;
        }
        
    }
    
    return false;
}

int main()
{
    vector<int> nums = {1,2,4,4,3,3,0,9,2,3};
    int k = 3;
    int sum = 0;
    vector<int> pairs;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i+1; j < nums.size(); j++)
        {   
            if (abs(nums[i] - nums[j]) == k && !find(pairs,nums[j]))
            {
                sum++;
                pairs.push_back(nums[j]);
            }
        }
        pairs.clear();
    }
    cout << sum;
}