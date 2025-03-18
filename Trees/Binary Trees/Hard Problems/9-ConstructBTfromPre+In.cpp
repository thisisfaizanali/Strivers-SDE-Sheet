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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        // map inorder values with index to find root and nums on left :
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; ++i)
            inMap[inorder[i]] = i;
        return buildSubTree(preorder, 0, n - 1, inorder, 0, n - 1, inMap);
    }
    TreeNode *buildSubTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder,
                           int inStart, int inEnd, unordered_map<int, int> &inMap)
    {
        // Base case :
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;
        // Construct root node :
        TreeNode *root = new TreeNode(preorder[preStart]);
        // find index of root Node :
        int inRoot = inMap[root->val];
        // numbers on left :
        int numsLeft = inRoot - inStart;
        // build left and right :
        root->left = buildSubTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = buildSubTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
        return root;
    }
};