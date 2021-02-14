#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    //Example of the input : [1,7,0,7,-8,null,null]
    string in;
    cin >> in;

    vector<pair<string,string>> nodes;

    /*Convert the input to array of nodes*/
    string node = "";
    int j = 1;
    while (in[j] != ']')
    {
        if (in[j] == ',')
        {
            nodes.push_back(make_pair(node,""));
            node = "";
            j++;
        }
        else
        {
            node += in[j];
            j++;
            if (in[j] == ']')
            {
                nodes.push_back(make_pair(node,""));
                node = "";
                break;
            }
        }
    }
    /* ====================== */

    cout << "TreeNode* root = new TreeNode(" + nodes[0].first + ");" << endl;

    int l = 0,r = 1;
    int counter = 0;
    while (l < r && r < nodes.size())
    {
        //combine the path of the root and the position of the node (left or right) 
        nodes[r].second = nodes[l].second + "->" + (counter == 0 ? "left" : "right");
        if (nodes[l].first == "null")
        {
            l++;
            continue;
        }
        if (nodes[r].first != "null")
        {
            cout << "root" + nodes[r].second + " = new TreeNode(" + nodes[r].first + ");" << endl ;
        }
        r++;
        counter++;
        if (counter == 2)
        {
            l++;
            counter = 0;
        }
    }

}