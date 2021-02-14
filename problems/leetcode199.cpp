#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>
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

vector<int> ans;

void bfs(TreeNode* root, int level)
{
    if (root == NULL)  return;
 
    // Create an empty queue for level order traversal
    queue<TreeNode *> q;
 
    // Enqueue Root and initialize height
    q.push(root);
 
    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        TreeNode *node = q.front();
        cout << node->val << " ";
        q.pop();
 
        /* Enqueue left child */
        if (node->left != NULL)
            q.push(node->left);
 
        /*Enqueue right child */
        if (node->right != NULL)
            q.push(node->right);
    }
}

void dfs(TreeNode* root, int level)
{
    if (root == nullptr)
    {
        return;
    }
    if (ans.size() < level)
    {
        ans.push_back(root->val);
    }
    dfs(root->right,level+1);
    dfs(root->left,level+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->left->left = new TreeNode(1);
    // root->left->left->left = new TreeNode(0);
    // root->left->left->right = new TreeNode(1);

    root->left->right = new TreeNode(5);
    // root->left->right->left = new TreeNode(1);
    // root->left->right->right = new TreeNode(0);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    // root->right->right->left = new TreeNode(1);
    // root->right->right->right = new TreeNode(0);

    // root->right->left = new TreeNode(3);
    // root->right->left->left = new TreeNode(-1);
    // root->right->left->right = new TreeNode(0);
    dfs(root,1);
    
}