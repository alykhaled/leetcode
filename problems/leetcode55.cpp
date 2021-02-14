#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
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
bool valid = true;

TreeNode* dfs(TreeNode* root,int low, int high)
{
    if (root->val < low)
    {
        root = root->right;
    }
    // else if (root->val > )
    // {
    //     /* code */
    // }
    
    
    else if(root->left == nullptr && root->right == nullptr)
    {
        return;    
    }
    else if(root->left == nullptr)
    {
        
    }
    else if(root->right == nullptr)
    {
        
    }
    else
    {
        if (root->left->val < low && root->left->val > high)
        {
            root->left = root->left->left;
        }
        
    }
    

    
}


int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    // root->left->left = new TreeNode(1);
    // root->left->left->left = new TreeNode(0);
    // root->left->left->right = new TreeNode(1);

    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    // root->left->right->right = new TreeNode(0);

    root->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    // root->right->right->left = new TreeNode(1);
    // root->right->right->right = new TreeNode(0);

    root->right->left = new TreeNode(3);
    // root->right->left->left = new TreeNode(-1);
    // root->right->left->right = new TreeNode(0);
    int low = 2,high = 3;
    dfs(root,low,high);
}