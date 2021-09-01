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

vector<double> averageOfLevels(TreeNode* root) 
{
    if (root == NULL)  return {0};
    vector<double> ans;
    // Create an empty queue for level order traversal
    queue<pair<TreeNode *,int>> q;
 
    // Enqueue Root and initialize height
    q.push(make_pair(root,1));
    int level = 1, count = 0;
    double sum = 0;
    while (q.empty() == false)
    {
        // Print front of queue and remove it from queue
        TreeNode *node = q.front().first;
        int currentLevel = q.front().second;
        q.pop();
        if (currentLevel != level)
        {
            level = currentLevel;
            ans.push_back(sum/count);
            sum = 0;
            count = 0;
        }
        sum += node->val;
        count++;
 
        /* Enqueue left child */
        if (node->left != nullptr)
            q.push(make_pair(node->left,currentLevel+1));
 
        /*Enqueue right child */
        if (node->right != nullptr)
            q.push(make_pair(node->right,currentLevel+1));

    }
    ans.push_back(sum/count);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);

    vector<double> a = averageOfLevels(root);
    for (auto &&i : a)
    {
        cout << i << " ";
    }
    
}