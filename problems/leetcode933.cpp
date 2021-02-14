#include <iostream>
#include <vector>
using namespace std;

int ping(int t,vector<int>& a)
{
    int n = 1;
    a.push_back(t);

    for (int i = a.size()-2; i >= 0; i--)
    {
        //cout << a[i] <<endl;
        if(a[i] >= (t - 3000))
        {
            n++;
        }
        else
        {
            cout << n <<endl;
            return n;
        }
    }
    cout << n <<endl;
    return n;
}

int main()
{
    vector<int> a;
    ping(1,a);
    ping(100,a);
    ping(3001,a);
    ping(3002,a);
    ping(5001,a);
    return 0;
}