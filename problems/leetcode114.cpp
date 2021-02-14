#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* flattenTree = new TreeNode(0);
int treeSize = 0;
TreeNode* finalTree = flattenTree;

void dfs(TreeNode* root)
{
    if(root == nullptr)
    {
        return;
    }
    flattenTree->val = root->val;
    treeSize++;
    flattenTree->right = new TreeNode();
    flattenTree = flattenTree->right;
    dfs(root->left);
    dfs(root->right);

}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    //root->left->left->left = new TreeNode(0);
    //root->left->left->right = new TreeNode(1);

    root->left->right = new TreeNode(4);
    // root->left->right->left = new TreeNode(-1);
    // root->left->right->right = new TreeNode(0);

    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    // root->right->right->left = new TreeNode(1);
    // root->right->right->right = new TreeNode(0);

    // root->right->left = new TreeNode(0);
    // root->right->left->left = new TreeNode(-1);
    // root->right->left->right = new TreeNode(0);

    TreeNode* here;
    here = root;    
    dfs(root);
    flattenTree = 0x0;
    for (int i = 0; i < treeSize; i++)
    {
        here->val = finalTree->val;
        here->left = nullptr;
        if (i == treeSize-1)
        {
            break;
        }
        if (here->right)
        {
            here = here->right;
        }
        else
        {
            here->right = new TreeNode();
            here = here->right;
        }
        if (finalTree->right)
        {
            finalTree = finalTree->right;
        }
        else
        {
            break;
        }
    }
    
    return 0;
}