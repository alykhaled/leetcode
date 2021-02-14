#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {0,0,0,1,0,1,0,1,1};
    int k = 1;
    bool ok = true;
    bool firstone = true;
    int c = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            if (!firstone)
            {
                if (c >= k)
                {
                    ok = true;
                    c = 0;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                firstone = false;
                c = 0;
            }
            
        }
        else
        {
            c++;
        }
        
    }
    cout << (ok ? "true" : "false");
    
}