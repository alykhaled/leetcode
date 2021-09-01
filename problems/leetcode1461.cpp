#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <math.h>
#include <unordered_set>
#include <stack>
using namespace std;

bool hasAllCodes(string s, int k) 
{
    unordered_set<string> st;
    int l = 0, r = k;
    while (l < r && r <= s.length())
    {
        st.insert(s.substr(l,k));
        l++;
        r++;
    }
    return st.size() == pow(2,k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    if (hasAllCodes("00110",2))
    {
        cout<< "Yes";
    }
    else
    {
        cout << "No";
    }
    
}