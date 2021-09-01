#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char,int> map;
    for(int i = 0; i < order.length(); i++)
    {
        map[order[i]] = i;
    }
    int maxL = words[0].length();

    for(int i = 0; i < words.size(); i++)
    {
        if(maxL < words[i].length())
        {
            maxL = words[i].length();
        }
    }
    
    for(int i = 0; i < maxL; i++)
    {
        for(int j = 0; j < words.size()-1; j++)
        {
            if(words[j].length() >= j)
            {
                if(words[j+1].length() >= j)
                {
                    if(map[words[j+1][i]] < map[words[j][i]])
                    {
                        return false;
                    }
                    else
                    {
                        
                    }   
                }
            }
            else
            {
                continue;
            }

        }   
    }
    return true;
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<string> words = {"hello","leetcode"};
    cout << ((isAlienSorted(words,"hlabcdefgijkmnopqrstuvwxyz")) ? "OK" : "NO");

}