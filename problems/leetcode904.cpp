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
    //Max of two distinct numbers in contiguos sub array 
    vector<int> tree = {0,1,6,6,4,4,6};
    if(tree.size() == 1)
    {
        return 1;
    }
    int firsttype = -1, secondtype = -1,secondlast;
    int l = 0, r = 1,ans = 1,maxl = 0;
    firsttype = tree[l];
    secondtype = tree[r];
    
    while (l < r && r < tree.size())
    {
        if(secondtype == firsttype && tree[r] != firsttype)
        {
            secondlast = r;
            secondtype = tree[r];
        } 
        if (tree[r] == firsttype)
        {
            ans++;
            r++;
        }
        else if (tree[r] == secondtype)
        {
            //secondlast = r;
            ans++;
            r++;
        }
        else
        {
            l = secondlast;
            firsttype = tree[l];
            r = secondlast+1;
            secondtype = tree[r];
            secondlast = r;
            //maxl = max(maxl,ans);
            ans = 1;
        }
        maxl = max(maxl,ans);

    }
    cout << maxl;
}