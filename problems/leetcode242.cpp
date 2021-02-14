#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

bool isAnagram(string s, string t) 
{
    if (s.length() != t.length())
    {
        return false;
    }
    
    // sort(s.begin(),s.end());
    // sort(t.begin(),t.end());
    // for (int i = 0; i < s.length(); i++)
    // {
    //     if (s[i] != t[i])
    //     {
    //         return false;
    //     }
    // }
    // return true;
    
    unordered_map<char,int> main;
    unordered_map<char,int> second;
    int uniqueS = 0;
    for (int i = 0; i < s.length(); i++)
    {
        main[s[i]]++;
    }
    uniqueS = main.size();
    int uniqueT = 0;
    for (int i = 0; i < t.length(); i++)
    {
        if (main.find(t[i]) != main.end())
        {
            second[t[i]]++;
            if (main[t[i]] == second[t[i]])
            {
                uniqueT++;
            }
        }
    }
    return uniqueS == uniqueT;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    if (isAnagram("cat","rat"))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
    
}