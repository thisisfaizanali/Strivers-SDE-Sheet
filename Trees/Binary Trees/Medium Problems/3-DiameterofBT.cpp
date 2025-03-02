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
    int diameterOfBinaryTree(TreeNode *root)
    {
        // mathematically : max(lh+rh) for every node :
        int diameter = 0;
        dfsHeight(root, diameter);
        return diameter;
    }
    int dfsHeight(TreeNode *root, int &diameter)
    {
        if (!root)
            return 0;
        int lh = dfsHeight(root->left, diameter);
        int rh = dfsHeight(root->right, diameter);
        // Update the global diameter
        diameter = max(diameter, lh + rh);
        // Return height of subtree rooted at this node
        return 1 + max(lh, rh);
    }
};
