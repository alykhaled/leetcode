#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

int main()
{
    string s = "ohvhjdml";

    /*HashMap*/
    string current = "";
    int maxle = 0,currentle = 0;
    map<char,int> map;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (map.find(s[i]) == map.end())
        {
            currentle++;
        }
        else
        {
            while (s[i] != current[0])
            {
                map.erase(map.find(current[0]));
                current.erase(current.begin(),current.begin()+1);
                currentle--;
            }
            map.erase(map.find(current[0]));
            current.erase(current.begin(),current.begin()+1);
        }
        map.insert(make_pair(s[i],i));
        current += s[i];
        maxle = max(maxle,currentle);
    }

    cout << maxle;
    
}