#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int numberOfArithmeticSlices(vector<int>& a) 
{
    if (a.size() < 3)
    {
        return 0;
    }
    int dp[100];
    int ar = 0;
    for (int i = 2; i < a.size(); i++)
    {
        if (a[i] - a[i-1] == a[i-1] - a[i-2])
        {
            dp[i] = dp[i-1] + +1;
        }
        ar += dp[i];
    }
    return ar;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {1, 2, 3, 4};
    cout << numberOfArithmeticSlices(a);
}