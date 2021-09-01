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

void dfs(TreeNode* root, int low, int high)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->right != nullptr && (root->right->val < low || root->right->val > high))
    {
        if (root->right->left == nullptr)
        {
            root->right = root->right->right;
        }
        else
        {
            root->right = root->right->left;
        }      
    }
    if (root->left != nullptr && (root->left->val < low || root->left->val > high))
    {
        if (root->left->left == nullptr)
        {
            root->left = root->left->right;
        }
        else
        {
            root->left = root->left->left;
        }
    }
    dfs(root->right,low,high);
    dfs(root->left,low,high);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    
    dfs(root,1,3);
}