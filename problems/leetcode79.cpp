#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
bool dfs(vector<vector<char>>& board,string word,int x,int y,int pos,int m,int n)
{
    if(pos == word.length())
    {
        return true;
    }
    if(x >= m || x < 0 || y >= n || y < 0 || board[x][y] != word[pos])
    {
        return false;
    }
    board[x][y] = '0';
    
    bool status =  dfs(board,word,x+1,y,pos+1,m,n) || dfs(board,word,x-1,y,pos+1,m,n) || dfs(board,word,x,y+1,pos+1,m,n) || dfs(board,word,x,y-1,pos+1,m,n);
    board[x][y] = word[pos];
    return status;
}
bool exist(vector<vector<char>>& board, string word) {
    if(word == "") return false;

    // return dfs(board,word,0,0,0,board.size(),board[0].size());
    for(int i = 0; i < board.size(); i++) 
        for(int j = 0; j < board[i].size(); j++) 
            //check if the characters are equal then call DFS
            if(board[i][j] == word[0] && dfs(board,word,i,j,0,board.size(),board[0].size()))
                return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<char>> v1 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << exist(v1,"ABCB");
    
}