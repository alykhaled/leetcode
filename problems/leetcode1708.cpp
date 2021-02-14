#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {4,5,6,2,3,1,9};
    int k = 4;
    int sum = 0;
    vector<int> newa;
    for (int i = 0; i < a.size(); i++)
    {
        if (i >= k)
        {
            if (newa[0] < a[i])
            {
                newa.erase(newa.begin(),newa.begin()+1);
                newa.push_back(a[i]);

            }
        }
        else
        {
            newa.push_back(a[i]);
        }
    }
    

    for (int i = 0; i < newa.size(); i++)
    {
        cout << newa[i] << " ";
    }
    
}