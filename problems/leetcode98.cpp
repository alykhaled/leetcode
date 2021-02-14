#include <iostream>
#include <vector>
#include <string>
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

void dfs(TreeNode* root)
{
    if(root->left == nullptr && root->right == nullptr)
    {
        return;    
    }
    else if(root->left == nullptr)
    {
        if (root->right->val > root->val)
        {
            dfs(root->right);
        }
        else
        {
            valid = false;
        }
    }
    else if(root->right == nullptr)
    {
        if (root->left->val < root->val)
        {
            dfs(root->left);
        }
        else
        {
            valid = false;
        }
    }
    else
    {
        if (root->left->val < root->val  && root->right->val > root->val)
        {
            dfs(root->left);
            dfs(root->right);
       
        }
        else
        {
            valid = false;
        }
    }
    

    
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    // root->left->left = new TreeNode(1);
    // root->left->left->left = new TreeNode(0);
    // root->left->left->right = new TreeNode(1);

    // root->left->right = new TreeNode(2);
    // root->left->right->left = new TreeNode(-1);
    // root->left->right->right = new TreeNode(0);

    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    // root->right->right->left = new TreeNode(1);
    // root->right->right->right = new TreeNode(0);

    root->right->left = new TreeNode(3);
    // root->right->left->left = new TreeNode(-1);
    // root->right->left->right = new TreeNode(0);

    dfs(root);
    if (valid)
    {
        cout << "VAlid";
    }
    else
    {
        cout << "False";
    }
    
    
}