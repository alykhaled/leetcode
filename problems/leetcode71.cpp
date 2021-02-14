#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    string path = "/.aa/....hidden";
    string st = "";
    st.push_back('/');
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '/')
        {
            if (!st.empty() && st.back() != '/' && i < path.length()-1)
            {
                st.push_back('/');
            }
            
        }
        else if (path[i] == '.')
        {
            bool notdot = false;
            string s = "";
            while (i < path.length() && path[i] != '/')
            {
                s+=path[i];
                i++;
            }
            if(s == "..")
            {
                if(!st.empty())
                {
                    st.pop_back();

                    while (!st.empty() && st.back() != '/' )
                    {
                        st.pop_back();
                        if(st.empty())
                        {
                            break;
                        }
                    }
                }
            }
            else if(s != ".")
            {
                st+=s;
                st.push_back('/');
            }
        }
        else
        {
            st.push_back(path[i]);
        }

    }
    if(st.empty())
    {
        st.push_back('/');
    }
    else if(st.length() > 1 && st.back() == '/')
    {
        st.pop_back();
    }
    if(!st.empty() && st[0] != '/')
    {
        st.insert(st.begin(),'/');
    }
    cout << st;
}