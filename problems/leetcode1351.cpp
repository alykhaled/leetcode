#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int left, int right)
{
    if (right >= left) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= 0)
        {
            return binarySearch(arr,mid+1,right); 
        } 
        else
        {
            return binarySearch(arr,left,mid-1); 
        }
    }
    return arr.size() - right - 1; 
}

int main()
{
    vector<vector<int>> grid = {{5,1,0},{-5,-5,-5}};
    int sum = 0;

    /*======== Brute Force ========
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] < 0)
            {
                sum++;
            }
        }
    } 
    */

    /*========= Binary Search ========*/
    for(int i = 0; i < grid.size(); i++)
    {
        int s = grid[i].size();
        sum += binarySearch(grid[i],0,grid[i].size()-1);
    } 
    cout << sum <<endl;
    return 0;
}

