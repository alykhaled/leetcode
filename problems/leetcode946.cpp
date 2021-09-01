#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
{
    if (pushed.size() == 0 && popped.size() == 0)
    {
        return true;
    }
    if (pushed.size() == 0 && popped.size() == 0)
    {
        return false;
    }
    
    
    stack<int> psh;
    int index = 0,poppedindex = 0;
    psh.push(pushed[index]);
    while (index < pushed.size() && poppedindex < popped.size())
    {
        if (!psh.empty() && psh.top() == popped[poppedindex])
        {
            poppedindex++;
            psh.pop();
        }
        else if(index == pushed.size()-1)
        {
            return false;
        }
        else
        {
            index++;
            psh.push(pushed[index]);
        }
        
    }
    return psh.empty();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<int> a = {3,0,1,2};
    vector<int> b = {2,3,1,0};
    cout << (validateStackSequences(a,b) ? "Yes" : "NO");
    
}