#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

string findLongestWord(string s, vector<string>& d) 
{
    string finalans = "";
    for (auto &&i : d)
    {
        int r = 0,index = 0;
        while (index != i.length() && r < s.length())
        {
            if (s[r] == i[index])
            {
                index++;
            }
            r++;            
        }
        if (index == i.length())
        {
            if (i.length() > finalans.length())
            {
                finalans = i;
            }
            else if (i.length() == finalans.length())
            {
                if (i < finalans)
                {
                    finalans = i;
                }
            }
        }
    }
    return finalans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<string> a = {"ale","apple","monkey","plea"};
    cout << findLongestWord("abpcplea",a);
}