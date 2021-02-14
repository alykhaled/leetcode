#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int maxl = 0;
    int squares=0;
    vector<vector<int>> rectangles = {{5,8},{3,9},{5,12},{16,5}};
    for (int i = 0; i < rectangles.size(); i++)
    {
        int small = min(rectangles[i][0],rectangles[i][1]);
        int large = max(rectangles[i][0],rectangles[i][1]);

        if (small > maxl)
        {
            squares = 1;
            maxl = small;
        }
        else if (small == maxl)
        {
            squares++;
        }
        
    }
    cout << squares << endl;
    
    return 0;
}