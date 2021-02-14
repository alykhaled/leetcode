#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int x = 745;
    int tempNum = x,revNum = 0,lastDigit = 0;
    if(x < 0)
    {
        if(x == INT_MIN)
        {
            return 0;
        }
        
        tempNum = -1 * x;
    }
    
    while(tempNum)
    {
        if(revNum > (INT_MAX / 10))
        {
            return 0;
        }
        
		lastDigit = tempNum % 10;
		
        revNum = lastDigit + revNum * 10;
        
        tempNum /= 10;
    }
    
    if(x < 0)
    {
        revNum *= -1;
    }
    
    cout << revNum;
    
    return 0;
}