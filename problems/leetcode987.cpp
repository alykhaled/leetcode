#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

map<int,map<int,vector<int>>> nums;

void dfs(TreeNode* root,int x,int y)
{
    if (root == nullptr)
    {
        return;
    }
    nums[y][x].push_back(root->val);
    dfs(root->left,x+1,y-1);
    dfs(root->right,x+1,y+1);
    
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    // root->left->left->left = new TreeNode(0);
    // root->left->left->right = new TreeNode(1);

    root->left->right = new TreeNode(2);
    // root->left->right->left = new TreeNode(-1);
    // root->left->right->right = new TreeNode(0);

    root->right = new TreeNode(4);
    // root->right->right = new TreeNode(2);
    // root->right->right->left = new TreeNode(1);
    // root->right->right->right = new TreeNode(0);

    root->right->left = new TreeNode(2);
    // root->right->left->left = new TreeNode(-1);
    // root->right->left->right = new TreeNode(0);
    vector<vector<int>> finals;
    dfs(root,0,0);
    for (auto itr = nums.begin(); itr != nums.end(); ++itr) 
    {
        vector<int> a;
        for (auto itr1 = nums[itr->first].begin(); itr1 != nums[itr->first].end(); ++itr1) 
        { 
            vector<int> b = itr1->second;
            sort(b.begin(),b.end());
            a.insert(a.end(), b.begin(), b.end());
        }
        finals.push_back(a); 
    } 
    
}