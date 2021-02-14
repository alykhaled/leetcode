#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums1 = {7,4}; 
    vector<int> nums2 = {5,2,8,9};
    
    long long sum = 0;
    if (nums1.size() >= nums2.size())
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums1.size(); j++)
            {
                for (int k = j+1; k < nums1.size(); k++)
                {
                    if (i < nums1.size() && j < nums2.size() && k < nums2.size())
                    {
                        long long mult = (long long)nums1[i] * (long long)nums1[i];
                        if (mult == (long long)nums2[j] * (long long)nums2[k])
                        {
                            sum++;
                        }
                    }
                    
                    if (i < nums2.size() && j < nums1.size() && k < nums1.size())
                    {
                        long long mult2 = (long long)nums2[i] * (long long)nums2[i];
                        if (mult2 == (long long)nums1[j] * (long long)nums1[k])
                        {
                            sum++;
                        }
                    }
                }
            }
        }

    }
    else
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                for (int k = j+1; k <nums2.size(); k++)
                {
                    if (i < nums1.size() && j < nums2.size() && k < nums2.size())
                    {
                        long long mult = (long long)nums1[i] * (long long)nums1[i];
                        
                        if (mult == (long long)nums2[j] * (long long)nums2[k])
                        {
                            sum++;
                        }
                    }
                    if (i < nums2.size() && j < nums1.size() && k < nums1.size())
                    {
                        long long mult2 = (long long)nums2[i] * (long long)nums2[i];
                        if (mult2 == (long long)nums1[j] * (long long)nums1[k])
                        {
                            sum++;
                        }
                    }
                    
                }
            }
        }
    }
    
    
    
    
    cout << sum;
    return 0;
}
