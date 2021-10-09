#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

 bool dfs(vector<int> calCounts, int requiredCals,int index,int amount)
 {
    if(index==calCounts.size())
    {
        if(amount==requiredCals)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if(dfs(calCounts,requiredCals,index+1,amount))
    {
        return true;
    }
    if(amount+calCounts[index]<=requiredCals)
    {
        return dfs(calCounts,requiredCals,index+1,amount+calCounts[index]);
    }
    return false;

 }

bool isPossible(vector<int> calCounts, int requiredCals) {
    return dfs(calCounts,requiredCals,0,0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> calCounts(n);
    for(int i=0;i<n;i++)
    {
        cin>>calCounts[i];
    }
    if(isPossible(calCounts,k))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}