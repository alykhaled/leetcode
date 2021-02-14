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
    vector<int> height = {1,2,1};
    int l=0,r = height.size()-1, ans = 0;
    while (l < r)
    {
        ans = max(ans,(r-l)*min(height[r],height[l]));
        if (height[l] < height[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    cout << ans;
    
}