/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root) // An empty tree is symmetric
            return true;
        // Check if left and right subtrees are mirror images
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (!left && !right) // Both subtrees are null, so they are symmetric
            return true;
        if (!left || !right) // One is null while the other isn't, so not symmetric
            return false;
        if (left->val != right->val) // Values do not match, so not symmetric
            return false;
        // Recursively check:
        // - Left subtree of `left` with right subtree of `right`
        // - Right subtree of `left` with left subtree of `right`
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};
