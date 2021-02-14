#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s = "?zs";
    vector<int> indexes;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '?')
        {
            for (int j = 0; j < 26; j++)
            {
                bool valid = true;

                if (i > 0 && j + 'a' == s[i-1])
                {
                    valid = false;
                }

                if (i < s.length()-1 && j + 'a' == s[i+1] && s[i+1] != '?')
                {
                    valid = false;
                }

                if (valid)
                {
                    s[i] = j + 'a';
                    break;
                }
            }

        }
    }

    
    cout << s;
    return 0;
}