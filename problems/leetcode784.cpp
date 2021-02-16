#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

vector<string> ans;
void rec(string s, string current,int index)
{
    if (index == s.length()-1)
    {
        current.push_back(s[index]);
        ans.push_back(current);
        if (s[index] >= 97 && s[index] <= 122)
        {
            current.pop_back();
            current.push_back(s[index]-32);
            ans.push_back(current);
        }
        else if (s[index] >= 65 && s[index] <= 90)
        {
            current.pop_back();
            current.push_back(s[index]+32);
            ans.push_back(current);
        }
        return;
    }
    current.push_back(s[index]);
    rec(s,current,index+1);
    if (s[index] >= 97 && s[index] <= 122)
    {
        current.pop_back();
        current.push_back(s[index]-32);
        rec(s,current,index+1);
    }
    else if (s[index] >= 65 && s[index] <= 90)
    {
        current.pop_back();
        current.push_back(s[index]+32);
        rec(s,current,index+1);
    }
}

vector<string> letterCasePermutation(string s) 
{
    rec(s,"",0);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    string s = "a1b2c";
    vector<string>ans = letterCasePermutation(s);
    for (auto &&i : ans)
    {
        cout << i << " "; 
    }
}