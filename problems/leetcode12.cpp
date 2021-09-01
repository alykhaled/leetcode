#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

string intToRoman(int num) 
{
    string s;
    vector<pair<int,string>> m {
        {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
    
    while(num > 0)
    {
        bool found = false;
        for (int i = 0; i < m.size() && !found; i++)
        {
            if (m[i].first <= num)
            {
                s += m[i].second;
                num -= m[i].first;
                found = true;
            }
        }
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    cout << intToRoman(1994);
}