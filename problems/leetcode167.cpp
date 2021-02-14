#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> ans(2);
    vector<int> dd;
    /*TWO POINTERS SOLUTION*/
    int a=0,b=numbers.size()-1;
    while (a <= b)
    {
        int sum = numbers[a] + numbers[b];
        if (sum > target)
        {
            b--;   
        }
        else if (sum < target)
        {
            a++;
        }
        else
        {
            ans[0] = a;
            ans[1] = b;
            return 0;
        }
    }
    
    /*BINARY SEARCH SOLTION*/
    //int imin = 0,imax = numbers.size()-1;
    //int sum = 0,n = 0;
    // while (imax >= imin)
    // {
    //     int imid = (imin + imax)/2;
    //     if (numbers[imid] < target)
    //     {
    //         imin = imid + 1;
    //         if (n == 0)
    //         {
    //             ans[n] = imid;
    //             n++;
    //             sum = numbers[imid];
    //         }
    //         else
    //         {
    //         }
    //     }
    //     else if (numbers[imid] > target)
    //     {
    //         imax = imid - 1;
    //     }
    //     else
    //     {
    //     }
    // }
    //cout << sum;

    return 0;
}
