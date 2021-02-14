#include <iostream>
using namespace std;
int main()
{
    int n = 1;
    int money = 0,c = 0, week = 1;
    for (int i = 1; i <= n; i++)
    {
        c++;
        money += c;
        if (i % 7 == 0)
        {
            c = week;
            week++;
        }
    }
    cout << money <<endl;
    
    return 0;
}