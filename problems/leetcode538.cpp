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

int sum = 0;
void dfs(TreeNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    dfs(root->right);
    sum += root->val;
    root->val = sum;
    dfs(root->left);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    // root->left->left->left = new TreeNode(0);
    // root->left->left->right = new TreeNode(1);

    root->left->right = new TreeNode(2);
    // root->left->right->left = new TreeNode(1);
    root->left->right->right = new TreeNode(3);

    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    // root->right->right->left = new TreeNode(1);
    root->right->right->right = new TreeNode(8);

    root->right->left = new TreeNode(5);
    // root->right->left->left = new TreeNode(-1);
    // root->right->left->right = new TreeNode(0);
    dfs(root);
}