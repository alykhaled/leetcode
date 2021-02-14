#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int left, int right,int x)
{
    if (left <= right)
    {
        int mid = left + (right - left)/2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return binarySearch(arr,left,mid-1,x);
        }
        else
        {
            return binarySearch(arr,mid+1,right,x);
        }
    }
    return -1;
    
}

int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 13;
    cout << binarySearch(nums,0,nums.size()-1,target) <<endl;
    return 0;
}