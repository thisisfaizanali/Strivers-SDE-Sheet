/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
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
    bool isBalanced(TreeNode *root)
    {
        return dfsHeight(root) != -1;
    }
    int dfsHeight(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = dfsHeight(root->left);
        // early return  : left subtree is unbalanced
        if (lh == -1)
            return -1;
        int rh = dfsHeight(root->right);
        // early return  : right subtree is unbalanced
        if (rh == -1)
            return -1;
        // formal definition :
        if (abs(lh - rh) > 1)
            return -1;
        return 1 + max(lh, rh);
    }
};