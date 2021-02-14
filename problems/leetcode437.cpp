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

int target = 3;
int ways = 0;

void dfs(TreeNode* root,int sum)
{
    
    if (root == nullptr)
    {
        return;
    }

    if (root->val + sum == target)
    {
        ways++;
    }

    if (root->right)
    {
        dfs(root->right,sum+root->val);
        dfs(root->right,0);
    }
    
    if (root->left)
    {
        dfs(root->left,0);
        dfs(root->left,sum+root->val);
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(5);
    // root->left->left = new TreeNode(3);
    // root->left->left->left = new TreeNode(3);
    // root->left->left->right = new TreeNode(-2);

    // root->left->right = new TreeNode(2);
    // root->left->right->left = new TreeNode(-1);
    // root->left->right->right = new TreeNode(1);

    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(5);
    // root->right->right->left = new TreeNode(1);
    // root->right->right->right = new TreeNode(0);

    // root->right->left = new TreeNode(3);
    // root->right->left->left = new TreeNode(-1);
    // root->right->left->right = new TreeNode(0);
    dfs(root,0);
    cout << ways;

}