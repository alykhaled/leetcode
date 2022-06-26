#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int oldestNonKid = 0;
    int sumDistance = 0;
    int sumHasKid = 0;
    int sumHasNoKid = 0;
    for (int i = 0; i < n; i++)
    {
        int age, type,distance;
        cout << "Enter age: " ;
        cin >> age;
        cout << "Enter type (0 for has a new kid and 1 for hasn't new kid): " ;
        cin >> type;
        cout << "Enter distance: " ;
        cin >> distance;
        if (type == 1)
        {
            if (age > oldestNonKid)
            {
                oldestNonKid = age;
            }
            sumHasNoKid++;
        }
        else
        {
            sumHasKid++;
            sumDistance += distance;
        }
    }
    cout << "The oldest non-kid kangaroo in the zoo has age of :" << oldestNonKid << endl;
    cout << "The average distance of kangaroos that have a new kid is: " << sumDistance / sumHasKid << endl;

}