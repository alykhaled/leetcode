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
    string secret   = "1122";
    string guess    = "1222";
    int bulls = 0 ,cows = 0;
    unordered_map<char,set<int>> map;
    for (int i = 0; i < secret.length(); i++)
    {
        map[secret[i]].insert(i);
    }
    for (int i = 0; i < guess.length(); i++)
    {
        if (map.find(guess[i]) != map.end())
        {
            if (map[guess[i]].find(i) != map[guess[i]].end())
            {
                bulls++;
                map[guess[i]].erase(i);
                if (map[guess[i]].empty())
                {
                    map.erase(guess[i]);
                }
                guess[i] = 'x';
            }            
            
            
        }
    }
    for (int i = 0; i < guess.length(); i++)
    {
        if (map.find(guess[i]) != map.end())
        {
            cows++;
            map[guess[i]].erase(map[guess[i]].begin());            
            if (map[guess[i]].empty())
            {
                map.erase(guess[i]);
            }
        }
    }
    cout << to_string(bulls) + "A" + to_string(cows) + "B";


    
}