#include <iostream>
#include <vector>
using namespace std;

vector<int> current;
vector<vector<int>> finals;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* MainRoot;
void dfs(TreeNode* root, int targetSum)
{
    if(root == nullptr)
    {
        current.pop_back();
        current.push_back(5);
        

    }
    else if ((root->left == nullptr && root->right == nullptr) && targetSum - root->val == 0)
    {
        current.push_back(root->val);
        if (current[0] != MainRoot->val)
        {
            current.insert(current.begin(),MainRoot->val);
        }
        
        finals.push_back(current);
        current.pop_back();
    }
    else if (root->left == nullptr && root->right == nullptr)
    {
        
    }
    else
    {
        current.push_back(root->val);
        if(root->right)
        {
            dfs(root->right,targetSum - root->val);   
        }
        if(root->left) 
        {
            dfs(root->left,targetSum - root->val);   
        }
        if (current.size() != 0)
        {
            current.pop_back();
        }
        

    }
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(0);
    root->left->left->right = new TreeNode(1);

    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(-1);
    root->left->right->right = new TreeNode(0);

    root->right = new TreeNode(1);
    root->right->right = new TreeNode(-1);
    root->right->right->left = new TreeNode(1);
    root->right->right->right = new TreeNode(0);

    root->right->left = new TreeNode(0);
    root->right->left->left = new TreeNode(-1);
    root->right->left->right = new TreeNode(0);
    
    MainRoot = root;
    dfs(root,2);
    return 0;
}