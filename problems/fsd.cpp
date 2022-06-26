#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int x[300],y[300];
    int counter = 0;
    int yIndex = 0;
    //40 35 47 12 20 43 10 15 91 70 30 12 33 20 250 14 17 3 90 13
    for (int i = 0; i < 20; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < 20; i++)
    {
        if (i % 5 == 0)
        {
            counter++;
            if (counter % 2 == 1)
            {
                y[yIndex] = x[i];
                yIndex++;
                y[yIndex] = x[i+1];
                yIndex++;
            }
            else
            {
                y[yIndex] = x[i];
                yIndex++;
            }
            
        }
        
    }
    for (int i = 0; i < 20; i++)
    {
        cout << y[i] << " ";
    }
}