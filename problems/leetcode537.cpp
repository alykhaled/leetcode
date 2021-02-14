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
    string a = "1+-1i";
    string b = "0+0i";
    int reala ,realb;
    string reals = "";
    int plusa, plusb;

    //Real A
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '+')
        {
            plusa = i;
            break;
        }
        else
        {
            reals += a[i];
        }
    }
    reala = stoi(reals);
    
    //Real B
    reals = "";
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '+')
        {
            plusb = i;
            break;
        }
        else
        {
            reals += b[i];
        }
    }
    realb = stoi(reals);


    int complexa,complexb;
    string complexs = "";
    //Complex A
    for (int i = plusa+1; i < a.size(); i++)
    {
        if (a[i] == 'i')
        {
            break;
        }
        else
        {
            complexs += a[i];
        }
    }
    complexa = stoi(complexs);
    complexs = "";
    for (int i = plusb+1; i < b.size(); i++)
    {
        if (b[i] == 'i')
        {
            break;
        }
        else
        {
            complexs += b[i];
        }
    }
    complexb = stoi(complexs);

    string finals = to_string((reala * realb) - (complexa * complexb))+ "+" + to_string((reala * complexb) + (realb * complexa)) + "i";
    cout << finals;
}