#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
using namespace std;

int main()
{
    vector<vector<char>> board ={{'.','.','.','.','5','.','.','1','.'}
                                ,{'.','4','.','3','.','.','.','.','.'}
                                ,{'.','.','.','.','.','3','.','.','1'}
                                ,{'8','.','.','.','.','.','.','2','.'}
                                ,{'.','.','2','.','7','.','.','.','.'}
                                ,{'.','1','5','.','.','.','.','.','.'}
                                ,{'.','.','.','.','.','2','.','.','.'}
                                ,{'.','2','.','9','.','.','.','.','.'}
                                ,{'.','.','4','.','.','.','.','.','.'}};
    
    set<char> rows;
    set<char> block;
    vector<set<char>> column(9); 
    bool valid = true;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] != '.' )
            {
                if (rows.find(board[i][j]) == rows.end() && column[j].find(board[i][j]) == column[j].end())
                {
                    rows.insert(board[i][j]);
                    column[j].insert(board[i][j]);  
                }
                else
                {
                    valid = false;
                    break;
                }
            }
            if (i % 3 == 0 && j % 3 == 0 )
            {
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        if(board[i+k][j+l] != '.')
                        {
                            if (block.find(board[i+k][j+l]) == block.end())
                            {
                                block.insert(board[i+k][j+l]);
                            }      
                            else
                            {
                                valid = false;
                                break;
                            }
                        }
                    }
                }
            }
            block.clear();
        }
        rows.clear();
    }
    if (valid)
    {
        cout << "true";
    }
    
    return 0;
}