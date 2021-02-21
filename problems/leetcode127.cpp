#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

bool oneChar(string x, string y)
{
    int c = 0;
    if (x == y)
    {
        return false;
    }
    
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] != y[i])
        {
            c++;
        }
    }
    return c==1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
{
    unordered_set<string> map(wordList.begin(), wordList.end());
    queue<string> que;
    int c = 0;
    que.push(beginWord);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            string current = que.front();
            que.pop();
            if (current == endWord)
            {
                return c + 1;
            }
            for (int i = 0; i < wordList.size(); i++)
            {
                if (map.find(wordList[i]) != map.end() && oneChar(current,wordList[i]))
                {
                    que.push(wordList[i]);
                }
            }
        }
        c++;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<string> a = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength("hit","cog",a) << endl;
}