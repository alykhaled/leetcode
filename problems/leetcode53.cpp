#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <limits>
#include <stack>
using namespace std;

int findMaxCrossSubArray(vector<int> a,int low ,int mid ,int high)
{
    int sum = 0, leftMax = INT_MIN; 
    for (int i = mid; i > low; --i) {
        sum += a[i];
        leftMax = max(leftMax, sum);
    }
    
    int rightMax = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i < high; ++i) 
    {
        sum += a[i];
        rightMax = max(rightMax, sum);
    }

    return leftMax + rightMax;
    
}

int findMaxSubArray(vector<int> a,int low ,int high)
{
    if (low == high)
    {
        return a[low];
    }
    else
    {
        int mid     = (low + high)/2;
        int left    = findMaxSubArray(a,low,mid);
        int right   = findMaxSubArray(a,mid + 1,high);
        int cross   = findMaxCrossSubArray(a,low,mid,high);
        return max(cross,max(left,right));
    } 
}                                        

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int finals = findMaxSubArray(nums,0,nums.size());
    cout << finals;
}