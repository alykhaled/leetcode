#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string text = "&&gt;";
    string finalt = "";
    string entity = "";
    bool start,end;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ';')
        {
            start = false;
            if (entity == "&quot")
            {
                finalt += "\"";
            }
            else if (entity == "&apos")
            {
                finalt += "\'";
            }
            else if (entity == "&amp")
            {
                finalt += "&";
            }
            else if (entity == "&gt")
            {
                finalt += ">";
            }
            else if (entity == "&lt")
            {
                finalt += "<";
            }
            else if (entity == "&frasl")
            {
                finalt += "/";
            }
            else
            {
                finalt += entity;
                finalt += ";";
            }
            entity = "";
            
        }
        else if (text[i] == '&')
        {
            if (i == 0)
            {
                entity += text[i];
                start = true;
            }
            else if (text[i-1] != '&')
            {
                entity += text[i];
                start = true;
            }
            else
            {
                finalt += "&";
            }
            
        }
        else if (start)
        {
            entity += text[i];
            start = true;
        }
        else if(!start)
        {
            finalt += text[i];
        }
    }
    cout << finalt;
    
}