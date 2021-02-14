#include <iostream>
#include <string>
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
int sum=0;
string num =""; 
void dfs(TreeNode* root)
{
    if(root == nullptr)
    {
        return;
    }
    if(root->right == nullptr && root->left == nullptr)
    {
        num += to_string(root->val);
        sum += stoi(num);
        num.pop_back();
        return;
    }
    num += to_string(root->val);
    dfs(root->left);
    dfs(root->right);
    num.pop_back();

}

int main()
{
    TreeNode* root = new TreeNode(1);
    //root->left = new TreeNode(9);
    //root->left->left = new TreeNode(5);
    //root->left->left->left = new TreeNode(0);
    //root->left->left->right = new TreeNode(1);

    //root->left->right = new TreeNode(1);
    // root->left->right->left = new TreeNode(-1);
    // root->left->right->right = new TreeNode(0);

    root->right = new TreeNode(5);
    //root->right->right = new TreeNode(6);
    // root->right->right->left = new TreeNode(1);
    // root->right->right->right = new TreeNode(0);

    // root->right->left = new TreeNode(0);
    // root->right->left->left = new TreeNode(-1);
    // root->right->left->right = new TreeNode(0);

    dfs(root);
    cout << sum;
    return 0;
}