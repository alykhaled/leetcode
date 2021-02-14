#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool find(vector<int>nums,int n)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == n)
        {
            return true;
        }
    }
    return false;
}
int sumA(vector<int>nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
       sum += nums[i];
    }
    return sum;
}

void removeDub(vector<int>&nums,int n,int &lefti)
{
    int i = 0;
    while (nums[0] != n)
    {
        nums.erase(nums.begin()+i);
        lefti--;
    }
    nums.erase(nums.begin()+i);

}

int main()
{
    vector<int> nums = {4,2,4,5,6};
    //vector<int> same(nums.size());
    vector<int> lift;
    int liftindex = 0;
    int liftsum = 0,rightsum = 0,maxs = 0,arraysum = 0;
    bool dub = true;
    for (int i = 0; i < nums.size(); i++)
    {
       arraysum += nums[i];
    }
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i; j < nums.size() && dub; j++)
    //     {
    //         if (!find(same,nums[j]))
    //         {
    //             same.push_back(nums[j]);
    //             sum += nums[j];
    //             maxs = max(maxs,sum);
    //             if (maxs >= arraysum / 2)
    //             {
    //                 break;
    //             }              
    //         }
    //         else
    //         {
    //             same.clear();
    //             dub = false;
    //             sum = 0;
    //         }
    //     }
    //     dub = true;
    // }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!find(lift,nums[i]))
        {
            lift.insert(lift.begin()+liftindex, nums[i]);
            liftindex++;
            liftsum = sumA(lift);
            maxs = max(maxs,liftsum);
        }
        else
        {
            if (arraysum - liftsum > liftsum)
            {
                removeDub(lift,nums[i],liftindex);
                lift.push_back(nums[i]);
            }
        }
    }
    cout << maxs;

    return 0;
}
