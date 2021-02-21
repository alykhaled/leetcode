#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

vector<string> ans;
void dfs(string s,int index,string current)
{
    if (index == s.length()-1)
    {
        if (s[index] == '2')
        {
            current.push_back('a');
            ans.push_back(current);
            current.pop_back();
            
            current.push_back('b');
            ans.push_back(current);
            current.pop_back();
            
            current.push_back('c');
            ans.push_back(current);
            current.pop_back();
        }
        else if (s[index] == '3')
        {
            current.push_back('d');
            ans.push_back(current);
            current.pop_back();
            current.push_back('e');
            ans.push_back(current);
            current.pop_back();
            current.push_back('f');
            ans.push_back(current);
            current.pop_back();
        }
        else if (s[index] == '4')
        {
            current.push_back('g');
            ans.push_back(current);
            current.pop_back();
            current.push_back('h');
            ans.push_back(current);
            current.pop_back();
            current.push_back('i');
            ans.push_back(current);
            current.pop_back();
        }
        else if (s[index] == '5')
        {
            current.push_back('j');
            ans.push_back(current);
            current.pop_back();
            current.push_back('k');
            ans.push_back(current);
            current.pop_back();
            current.push_back('l');
            ans.push_back(current);
            current.pop_back();
        }
        else if (s[index] == '6')
        {
            current.push_back('m');
            ans.push_back(current);
            current.pop_back();
            current.push_back('n');
            ans.push_back(current);
            current.pop_back();
            current.push_back('o');
            ans.push_back(current);
            current.pop_back();
        }
        else if (s[index] == '7')
        {
            current.push_back('p');
            ans.push_back(current);
            current.pop_back();
            current.push_back('q');
            ans.push_back(current);
            current.pop_back();
            current.push_back('r');
            ans.push_back(current);
            current.pop_back();
            current.push_back('s');
            ans.push_back(current);
            current.pop_back();
        }
        else if (s[index] == '8')
        {
            current.push_back('t');
            ans.push_back(current);
            current.pop_back();
            current.push_back('u');
            ans.push_back(current);
            current.pop_back();
            current.push_back('v');
            ans.push_back(current);
            current.pop_back();
        }
        else if (s[index] == '9')
        {
            current.push_back('w');
            ans.push_back(current);
            current.pop_back();
            current.push_back('x');
            ans.push_back(current);
            current.pop_back();
            current.push_back('y');
            ans.push_back(current);
            current.pop_back();
            current.push_back('z');
            ans.push_back(current);
            current.pop_back();
        }

        return;
    }
    if (s[index] == '2')
    {
        current.push_back('a');
        dfs(s,index+1,current);
        current.pop_back();
        
        current.push_back('b');
        dfs(s,index+1,current);
        current.pop_back();
        
        current.push_back('c');
        dfs(s,index+1,current);
        current.pop_back();
    }
    else if (s[index] == '3')
    {
        current.push_back('d');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('e');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('f');
        dfs(s,index+1,current);
        current.pop_back();
    }
    else if (s[index] == '4')
    {
        current.push_back('g');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('h');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('i');
        dfs(s,index+1,current);
        current.pop_back();
    }
    else if (s[index] == '5')
    {
        current.push_back('j');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('k');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('l');
        dfs(s,index+1,current);
        current.pop_back();
    }
    else if (s[index] == '6')
    {
        current.push_back('m');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('n');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('o');
        dfs(s,index+1,current);
        current.pop_back();
    }
    else if (s[index] == '7')
    {
        current.push_back('p');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('q');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('r');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('s');
        dfs(s,index+1,current);
        current.pop_back();
    }
    else if (s[index] == '8')
    {
        current.push_back('t');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('u');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('v');
        dfs(s,index+1,current);
        current.pop_back();
    }
    else if (s[index] == '9')
    {
        current.push_back('w');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('x');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('y');
        dfs(s,index+1,current);
        current.pop_back();
        current.push_back('z');
        dfs(s,index+1,current);
        current.pop_back();
    }

}

vector<string> letterCombinations(string digits)
{
    dfs(digits,0,"");
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<string> a = letterCombinations("23");
    for (auto &&i : a)
    {
        cout << i << " ";
    }
    
}