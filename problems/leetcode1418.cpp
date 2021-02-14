#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    vector<vector<string>> orders = {{"David","3","Ceviche"},{"Corina","10","Beef Burrito"},{"David","3","Fried Chicken"},{"Carla","5","Water"},{"Carla","5","Ceviche"},{"Rous","3","Ceviche"}};
    vector<vector<string>> finals;
    set<int> tables;
    set<string> foods;
    unordered_map<string,map<string,int>> items;
    for (int i = 0; i < orders.size(); i++)
    { 
        tables.insert(stoi(orders[i][1]));
        foods.insert(orders[i][2]);
        items[orders[i][1]][orders[i][2]]++; 
    }
    vector<string> header;
    header.push_back("Table");
    for (auto i : foods)
    {
        header.push_back(i);
    }
    finals.push_back(header);
    //sort(tables.begin(),tables.end());
    for (auto i : tables)
    {
        vector<string> table;
        table.push_back(to_string(i));
        for (auto j : foods)
        {
            table.push_back(to_string(items[to_string(i)][j]));     
        }
        finals.push_back(table);
    }
    for (int i = 0; i < finals.size(); i++)
    {
        for (int j = 0; j < finals[i].size(); j++)
        {
            cout << finals[i][j] << "\t";
        }
        cout << "\n";
    }
    
}