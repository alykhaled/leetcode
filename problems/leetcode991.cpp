#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int minMove = INT_MAX;
int ok = false;
void recure(int x,int y , int operation)
{
    if (x > y)
    {
        recure(x-1,y,operation+1);
        return;
    }
    else if (x == y)
    {
        minMove = min(minMove,operation);
        return;
    }
    else 
    {
        recure(x*2,y,operation+1);
        if(x > 0){recure(x-1,y,operation+1);}
    }
}

int brokenCalc(int x, int y) 
{
    // if (x > y)
    // {
    //     return x - y;
    // }
    // if (x == y)
    // {
    //     return 0;
    // }
    // if (x < y)
    // {
    //     if (y % 2 == 0)
    //     {
    //         return brokenCalc(x,y/2)+1;
    //     }
    //     else
    //     {
    //         return brokenCalc(x,y+1)+1;
    //     }
    // }
    recure(x,y,0);
    return minMove;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    cout << brokenCalc(2,3);
}