#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};

    for (int i = 0; i < nums2.size(); i++)
    {
        
    }
}

int binarysearch(vector<int> arr,int left,int right,int x)
{
    if (left<=right)
    {
        int mid = left + (right - left) / 2; 
        if (arr[mid] == x)
        {
            return mid-1;
        }
        if (arr[mid] < x && arr[mid+1] > x)
        {
            
            
        }
        
        
    }
    
}