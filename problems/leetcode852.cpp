#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right -left )/2;
        if (arr[mid] < arr[mid+1])
        {
            return binarySearch(arr,mid+1,right);
        }
        else
        {
            return binarySearch(arr,left,mid);
        }
    }
    return left;
}

int main()
{
    int peak = 0;
    vector<int> arr = {24,69,100,99,79,78,67,36,26,19};

    /*=========== Brute Force ============
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[i-1])
        {
            peak = i;
        }
    }
    cout << peak;
    */

   /*Binary Search*/
    peak = binarySearch(arr,0,arr.size()-2);
    cout << peak;
    return 0;
}