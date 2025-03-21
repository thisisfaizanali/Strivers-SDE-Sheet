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
    TreeNode *build(vector<int> &preorder, int &index, int bound)
    {
        if (index >= preorder.size() || preorder[index] > bound)
            return nullptr;
        // Create the root node :
        TreeNode *root = new TreeNode(preorder[index++]);
        // Recursively build the left and right subtrees :
        // when going left : bound -> root->val :
        root->left = build(preorder, index, root->val);
        // when going right : bound = bound :
        root->right = build(preorder, index, bound);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        // I will use the concept of bound (ranges from check/validate)
        // can only be done using upper Bound or bound :
        int index = 0;
        // bound is initialized with INT_MAX
        return build(preorder, index, INT_MAX);
    }
};