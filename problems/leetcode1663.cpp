#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int n = 5,k = 73;
    vector<int> nums;
    string s = "";
    while (k != 0)
    {
        if (k-26 < n)
        {
            
            nums.push_back(k-(n-1));
            k -= (k-(n-1));
            for (int i = 0; i < n; i++)
            {
                k--;
                nums.push_back(1);
            }
            
        }
        else
        {
            k-=26;
            nums.push_back(26);
        }
        n--;
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        s+= (nums[i] + 96);
    }
    cout << s;
    
}