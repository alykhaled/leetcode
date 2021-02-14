#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

int main()
{
    string S = "ababcbacadefegdehijhklij";
    unordered_map<char,int> map;
    vector<int> sol;
    for (int i = 0; i < S.length(); i++)
    {
        map[S[i]] = i;
    }

    int start = 0, end = S.length();
    for (int i = 0; i < S.length(); i++)
    {
        end = max(end,map[S[i]]);
        if (i == end)
        {
            sol.push_back(end-start+1);
            start = end +1;
        }   
    }
}