#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool has(set<int> a,int n)
{

    if (a.find(n) != a.end())
    {
        return true;
    }
    
    return false;
}

int main()
{
    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    vector<bool> keys(rooms.size());
    bool can = true;
    for (int i = 0; i < rooms.size(); i++)
    {
        keys[i] = false;   
    }

    for (int i = 0; i < rooms.size(); i++)
    {
        for (int j = 0; j < rooms[i].size(); j++)
        {
            keys[rooms[i][j]] = true;
        } 
    }

    for (int i = 0; i < rooms.size(); i++)
    {
        if (!keys[i])
        {
            can = false;
        }
    }

    
    if (can)
    {
        cout << "False"<<endl;
    }
    else
    {
        cout << "True"<<endl;

    }
    
    
    
    return 0;
}