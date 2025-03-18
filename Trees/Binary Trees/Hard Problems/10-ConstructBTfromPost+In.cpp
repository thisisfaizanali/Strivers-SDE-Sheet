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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        // map inorder values with index to find root and nums on left :
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; ++i)
            inMap[inorder[i]] = i;
        return buildSubTree(inorder, 0, n - 1, postorder, 0, n - 1, inMap);
    }
    TreeNode *buildSubTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder,
                           int postStart, int postEnd, unordered_map<int, int> &inMap)
    {
        // Base case :
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;
        // Construct root node :
        TreeNode *root = new TreeNode(postorder[postEnd]);
        // find index of root Node :
        int inRoot = inMap[root->val];
        // numbers on left :
        int numsLeft = inRoot - inStart;
        // build left and right :
        root->left = buildSubTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);
        root->right = buildSubTree(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);
        return root;
    }
};