#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int ones = 0;
    uint32_t g = 000000000000000000100000000001011;
    string s = to_string(g);
    for(int i =0; i <s.length(); i++)
    {
        if(s[i] == '1')
        {
            ones++;
        }
    }
}