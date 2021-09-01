#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

class FreqStack {
public:
    vector<int> st;
    //set<int> setE;
    unordered_map<int,int> map;
    int maxE;
    int maxFreq;
    FreqStack() {
        maxFreq = 0;
        maxE = 0;
    }
    
    void push(int x) {
        st.push_back(x);
        map[x]++;
        if (map[x] > maxFreq)
        {
            maxFreq = map[x];
        }
        
    }
    
    int pop() {
        int ans = 0;
        for (int i = st.size() - 1; i >= 0; i--)
        {
            if (map[st[i]] == maxFreq)
            {
                ans = st[i];
                maxE = st[i];
                st.erase(st.begin()+i);
                break;
            }
            
        }
        
        map[maxE]--;
        maxFreq--;
        for(auto it = map.cbegin(); it != map.cend(); ++it ) 
        {
            if (it ->second > maxFreq) {
                maxE = it->first;
                maxFreq = it->second;
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    FreqStack* obj = new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);
    cout << obj->pop() <<endl;
    cout << obj->pop() <<endl;
    cout << obj->pop() <<endl;
    cout << obj->pop() <<endl;
 
}