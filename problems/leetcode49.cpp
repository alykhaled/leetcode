#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
using namespace std;

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> finals;
    map<char,int> word;
    map<map<char,int>,vector<string>> map;
    for (int i = 0; i < strs.size(); i++)
    {
        for (int j = 0; j < strs[i].size(); j++)
        {
            word[strs[i][j]]++;
        }
        map[word].push_back(strs[i]);
        word.clear();
    }
    
    for (auto itr : map) 
    { 
        finals.push_back(itr.second);
    } 
    
}