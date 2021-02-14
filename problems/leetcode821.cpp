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

    string s = "baaa";
    /*
    0 l
    1 o
    2 v
    3 e
    4 l
    5 e
    6 e
    7 t
    8 c
    9 o
   10 d
   11 e
    */

   /*
   0 b
   1 a
   2 a
   3 a
   */
    char c = 'b';
    vector<int> ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            ans.push_back(0);
            continue;
        }
        int left = i-1, right= i+1, step = 1;
        while (left >= 0 || right < s.length())
        {
            if ( (left < 0 ? false : s[left] == c) || (right > s.length() ? false : s[right] == c))
            {
                ans.push_back(step);
                break;
            }
            else
            {
                left--;
                right++;
                step++;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    
    
}