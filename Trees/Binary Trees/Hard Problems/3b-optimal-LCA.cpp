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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // base case :
        if (!root || root == p || root == q)
            return root;
        // recursion for left and right subtree :
        TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q);
        // If both sides return a node, root is LCA
        if (leftLCA && rightLCA)
            return root;
        // Else return the non-null node
        return leftLCA ? leftLCA : rightLCA;
    }
};
