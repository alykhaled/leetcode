#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

bool binarySearch(vector<vector<int>> nums,int rS,int rE,int cS, int cE,int value)
{
    if(rS>rE||cS>cE){
        return false;
    }
    int rM = (rS + rE) / 2; 
    int cM = (cS + cE) / 2; 
    if (nums[rM][cM] == value)
    {
        return true;
    }
    if (nums[rM][cM] > value)
    {
        return binarySearch(nums,rS,rM - 1,cS,cM-1,value) || binarySearch(nums,rM,rE,cS,cM-1,value) || binarySearch(nums,rS,rM - 1,cM,cE,value) ;
    }
    else
    {
        return binarySearch(nums,rM+1,rE,cM+1,cE,value) || binarySearch(nums,rM+1,rE,cS,cM,value) || binarySearch(nums,rS,rM,cM+1,cE,value) ;
    }
}

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    int l = 0;
    int r = m-1;
    while (l < m && r >= 0)
    {
        if (matrix[l][r] == target)
        {
            return true;
        }
        else if (matrix[l][r] > target)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> a = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout << (searchMatrix(a,5) ? "YES" : "NO");
}