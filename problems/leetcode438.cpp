#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

vector<int> findAnagrams(string s, string p) 
{
    vector<int> ans;
    vector<int> word(26);
    for (int i = 0; i < p.length(); i++)
    {
        word[p[i] - 'a']++;
    }
    int n = p.length();
    vector<int> currentWord(26);
    int l = 0, r = 0;
    
    while (l <= r && r < s.length())
    {
        currentWord[s[r]- 'a']++;
        if (r - l + 1 > n)
        {
            currentWord[s[l] - 'a']--;
            l++;
        }
        if (currentWord == word)
        {
            currentWord[s[l] - 'a']--;
            ans.push_back(l);
            l++;
        }
        r++;
        
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> ans = findAnagrams("abab","ab");
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
}