#include <iostream>
using namespace std;

int main()
{
    int x[30];
    for (int i = 0; i < 30; i++)
    {
        cin >> x[i];
    }
    int min = 9999;
    for (int i = 0; i < 29; i+=2)
    {
        if (x[i] % x[i+1] == 0 || x[i+1] % x[i] == 0)
        {
            if(x[i] < x[i+1])
            {
                if (x[i] < min)
                {
                    min = x[i];
                }
                x[i+1] -= x[i];
            }
            else
            {
                if (x[i+1] < min)
                {
                    min = x[i+1];
                }
                x[i] -= x[i+1];
            }
        }
    }
    for (int i = 0; i < 30; i++)
    {
        cout << x[i]  << " ";
    }
    cout << endl;
    cout << "Minumum: " << min;
    
}