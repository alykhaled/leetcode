#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "G()()()()(al)";
    string f = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' && s[i+1] == 'a')
        {
            f.push_back('a');
            f.push_back('l');
            i += 3;
        }
        else if (s[i] == '(')
        {
            f.push_back('o');
            i++;
        }
        else
        {
            f.push_back(s[i]);
        }   
    }
    cout << f<<endl;
    
    return 0;
}