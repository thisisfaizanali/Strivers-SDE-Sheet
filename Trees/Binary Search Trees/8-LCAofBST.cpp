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
        // generic lca will work but lets utilise BST property :
        while (root)
        {
            // if p and q are both lesser than root->val : go left
            if (p->val < root->val && q->val < root->val)
                root = root->left;
            // else if both greater : go right
            else if (p->val > root->val && q->val > root->val)
                root = root->right;
            // else we have the split point which is our answer :
            else
                return root;
        }
        return nullptr;
    }
};