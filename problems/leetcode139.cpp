#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string,int> map;
    for(int i = 0; i < wordDict.size(); i++)
    {
        map[wordDict[i]]++;
    }
    string st = "";
    for(int i = 0; i < s.length();i++)
    {
        st+=s[i];
        if(map[st] == 1)
        {
            st = "";
        }
        if(map[st] == 1 && i == s.length()-1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    
}