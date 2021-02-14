#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
using namespace std;

int main()
{
    vector<string> names = {"kaido","kaido(1)","kaido","kaido(1)","kaido(2)"};
    // set<string> map;
    map<string,int> map;
    for (int i = 0; i < names.size(); i++)
    {
        if (map.count(names[i]) == 0)
        {
            map[names[i]] = 0;
        }
        else
        {
            map[names[i]]++; 

            int k = map[names[i]];
            string current = names[i];
            
            current += "(" + to_string(k) + ")"; 
 
            while (map.count(current) != 0)
            {
                k++; 
                current = names[i] +  "(" + to_string(k) + ")";
            }
            names[i] = current;
            map[names[i]] = 0;           
        }
    }

    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << " ";
    }
    
}