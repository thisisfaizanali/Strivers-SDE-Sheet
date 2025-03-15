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
    bool findPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &path)
    {
        // root to node func :
        if (!root)
            return false;
        path.push_back(root);
        if (root == target)
            return true;
        if (findPath(root->left, target, path) || findPath(root->right, target, path))
            return true;
        path.pop_back();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // last common element of the two paths :
        vector<TreeNode *> path1, path2;
        if (!findPath(root, p, path1) || !findPath(root, q, path2))
            return nullptr;
        int i = 0;
        while (i < path1.size() && i < path2.size() && path1[i] == path2[i])
            i++;
        return path1[i - 1];
    }
};
