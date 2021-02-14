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


int maxLevelSum(TreeNode* root) 
{
    queue<pair<TreeNode*,int>> que;
    vector<int> levels(10001,0);
    int maxSum = root->val;
    int maxLevel = 1;
    int nextLevel;
    que.push({root,1});
    while(!que.empty())
    {
        TreeNode* currentNode = que.front().first;
        int level = que.front().second;
        que.pop();
        levels[level] += currentNode->val;
        if(currentNode->right != nullptr) {que.push({currentNode->right,level+1});}
        if(currentNode->left != nullptr) {que.push({currentNode->left,level+1});}
        nextLevel = (que.empty() ? level + 1 : que.front().second) ;

        if (nextLevel != level && levels[level] > maxSum)
        {
            maxSum = levels[level];
            maxLevel = level;
        }
    }
    
    return maxLevel;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    TreeNode* root1 = new TreeNode(-100);
    root1->right = new TreeNode(-300);
    root1->right->left = new TreeNode(-10);
    root1->left = new TreeNode(-200);
    root1->left->left = new TreeNode(-20);
    root1->left->right = new TreeNode(-5);

    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(0);
    root2->left = new TreeNode(1);
    root2->left->right = new TreeNode(-8);
    root2->left->left = new TreeNode(7);
    root2->right->left = new TreeNode(-7);
    root2->right->right = new TreeNode(9);

    //cout << maxLevelSum(root2)<<endl;
    cout << maxLevelSum(root1) <<endl;
}