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
    int x = 4;
    int y =14;
    int z = 8;
    for(int i = 10; i>=3 ;i--)
    {
        if(i % 2 == 0)
        {
            if((y > x) && (y % z == 7))
            {
                cout << y <<endl;
                cout << z <<endl;
                x = x+1;
                cout << x << endl;
            }
            y++;
            cout << "OK" << endl;
        }
        if(i%3 == 0)
        {
            y = y+1;
            cout << x << endl << y << endl << z << endl;
            cout << "YES" << endl;
        }
    }
}