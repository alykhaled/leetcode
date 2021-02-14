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
int length = 0;
int minLength = 27;
string text = ""; 
string smalltext = ""; 
void dfs(TreeNode* root)
{
    if(root == nullptr)
    {
        return;
    }
    if(root->right == nullptr && root->left == nullptr)
    {
        // if (length < minLength)
        // {
        //     minLength = length;
        //     text.push_back(root->val + 97);
        //     smalltext = text;
        // }
        // return;
        
    }
    length++;
    text.push_back(root->val + 97);
    dfs(root->left);
    dfs(root->right);
    length--;
    text.pop_back();

}

int main()
{
    TreeNode* root = new TreeNode(25);
    root->left = new TreeNode();
    root->left->left = new TreeNode(3);
    //root->left->left->left = new TreeNode(0);
    //root->left->left->right = new TreeNode(1);

    root->left->right = new TreeNode(4);
    // root->left->right->left = new TreeNode(-1);
    // root->left->right->right = new TreeNode(0);

    root->right = new TreeNode(2);
    root->right->right = new TreeNode(4);
    // root->right->right->left = new TreeNode(1);
    // root->right->right->right = new TreeNode(0);

    root->right->left = new TreeNode(3);
    // root->right->left->left = new TreeNode(-1);
    // root->right->left->right = new TreeNode(0);

    dfs(root);
    int n = smalltext.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(smalltext[i], smalltext[n - i - 1]); 
    cout << smalltext;
    return 0;
}