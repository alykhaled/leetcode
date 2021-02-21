#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

struct compareFreq {

    inline bool operator() (pair<string,pair<int,int>>& a, pair<string,pair<int,int>>& b) 
    {
        return a.second.second < b.second.second; 
    }
};

vector<string> topKFrequent(vector<string>& words, int k) 
{
    int c = 0;
    unordered_map<string,pair<int,int>> map;
    for (auto &&i : words)
    {
        if (map.find(i) != map.end())
        {
            map[i].first++;
        }
        else
        {
            map[i].first++;
            map[i].second = c;
            c++;        
        }
    }
    vector<pair<string,pair<int,int>>> sortedFreq;
    for (auto &&i : map)
    {
        sortedFreq.push_back(i);
    }
    sort(sortedFreq.begin(), sortedFreq.end(), compareFreq());
    vector<pair<string,pair<int,int>>> sortedIndex;
    for (int i = 0; i < sortedFreq.size(); i++)
    {
        sortedIndex.push_back(sortedFreq[i]);
    }
    //sort(sortedIndex.begin(), sortedIndex.end(), compareIndex());
    //i love leetcode kk
    //4 3    3        3
    vector<string> ans;
    vector<string> temp;
    for (int i = 0; i < sortedIndex.size(); i++)
    {
        if (i == sortedIndex.size()-1)
        {
            if (sortedIndex[i].second.first == sortedIndex[i-1].second.first)
            {
                temp.push_back(sortedIndex[i].first);
                sort(temp.begin(),temp.end());
                ans.insert(ans.end(),temp.begin(),temp.end());
                temp.clear();
            }
            else
            {
                temp.push_back(sortedIndex[i].first);
                sort(temp.begin(),temp.end());
                ans.insert(ans.end(),temp.begin(),temp.end());
            }
        }
        else
        {
            if (sortedIndex[i].second.first == sortedIndex[i+1].second.first)
            {
                temp.push_back(sortedIndex[i].first);
                sort(temp.begin(),temp.end());
                ans.insert(ans.end(),temp.begin(),temp.end());
                temp.clear();
            }
            else
            {
                temp.push_back(sortedIndex[i].first);
            }
        }
        
        
        
    }
    vector<string> finals(ans.begin(),ans.begin()+k);
    return finals;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    vector<string>ans = topKFrequent(words,4);
    for (auto &&i : ans)
    {
        cout << i << " ";
    }
    
}