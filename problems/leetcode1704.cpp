#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s = "textbook";
    string a="",b="";
    int avowels= 0,bvowels = 0;
    for (int i = 0; i < s.length()/2; i++)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            avowels++;
        }
    }
    for (int i = s.length()/2; i < s.length(); i++)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            bvowels++;
        }
    }
    cout << avowels << " " << bvowels ;
    
    return 0;
} 