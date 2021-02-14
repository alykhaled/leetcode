#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2}; 
    // 2 1 1 2 1 1
    int k = 2;
    int l = 0,r = 0,c = 0,nice = 0;
    while (l <= r && r < nums.size())
    {
        if (nums[r] % 2 != 0)
        {
            c++;
        }
        if (c == k)
        {
            nice++;
            if (nums[l] % 2 != 0)
            {
                c--;
            }
            l++;
        }
        r++;   
    }
    cout << nice;
}