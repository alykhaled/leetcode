#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<vector<int>> boxTypes = {{1,3},{5,5},{2,5},{4,2},{4,1},{3,1},{2,2},{1,3},{2,5},{3,2}};
    int truckSize   = 35;
    int size        = 0;
    int units       = 0;
    int maxSize     = 0;
    int maxIndex    = 0;
    
    while (size!=truckSize)
    {
        if (boxTypes.size() == 0)
        {
            break;
        }
        
        for (int i = 0; i < boxTypes.size(); i++)
        {
            if (maxSize <= boxTypes[i][1])
            {
                maxIndex = i;
                maxSize = boxTypes[i][1];
            }
        }
        for (int i = 0; i < boxTypes[maxIndex][0]; i++)
        {
            if (size + 1 <= truckSize)
            {
                size++;
                units += boxTypes[maxIndex][1];
            }
        }
        boxTypes.erase(boxTypes.begin()+maxIndex);
        maxSize = 0;
        
    }
    cout << units << endl;
    

    return 0;
}