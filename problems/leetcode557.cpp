#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

string help(string s)
    {
        int left = 0;
        int right = s.length() - 1;
        while(left <= right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return s;
    }
    string reverseWords(string s) {
        string sub = "";
        string ans = "";
        for(int i = 0; i < s.length();i++)
        {
            if(s[i] == ' ' || i == s.length()-1)
            {
                ans += help(sub) + " ";
                sub = "";
            }
            else
            {
                sub+=s[i];    
            }
        }
        return ans;
    }
    
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    string s = "Let's take LeetCode contest";
    cout << reverseWords(s) << endl;
}