#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int minSteps(string s, string t) {
    unordered_map<char,int> mapS;
    unordered_map<char,int> mapT;
    for(auto i : s)
    {
        mapS[i]++;
    }
    for(auto i : t)
    {
        mapT[i]++;
    }
    int ans = 0;
    for(auto item : mapT)
    {
        ans += abs(mapS[item.first] - item.second);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    string s = "bab";
    string t = "aba";
    cout << minSteps(s,t) << endl;
    return 0;
}