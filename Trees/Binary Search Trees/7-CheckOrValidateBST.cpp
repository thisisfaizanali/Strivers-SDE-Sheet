/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
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
    bool isValidBST(TreeNode *root)
    {
        // recursion like for child sum : immediate left and right wont work
        // the entire tree should uphold : L<N<R
        // we will use ranges : at beginning [longmin,longmax]
        return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isValidBSTHelper(TreeNode *node, long minVal, long maxVal)
    {
        // Base case: an empty tree is a valid BST
        if (!node)
            return true;
        // Check if the current node violates the BST property
        if (node->val <= minVal || node->val >= maxVal)
            return false;
        // Recursively check the left and right subtrees
        // Left subtree: all values must be < node->val
        // Right subtree: all values must be > node->val
        return isValidBSTHelper(node->left, minVal, node->val) &&
               isValidBSTHelper(node->right, node->val, maxVal);
    }
};