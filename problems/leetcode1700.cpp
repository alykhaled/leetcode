#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> students    =    {1,1,1,0,0,1};
    vector<int> sandwiches  =    {1,0,0,0,1,1};
    int stuOne = 0,stuZero = 0, sanOne = 0, sanZero = 0;
    int i = 0;
    int iterate = 0;
    while(students.size() != 0 && iterate != students.size())
    {
        if (students[i] == sandwiches[i])
        {
            students.erase(students.begin()+i);
            sandwiches.erase(sandwiches.begin()+i);
            iterate = 0;
        }
        else
        {
            students.push_back(students[i]);
            students.erase(students.begin()+i);
            iterate++;
        }
        
    }

    cout << students.size()<<endl;
    return 0;
}