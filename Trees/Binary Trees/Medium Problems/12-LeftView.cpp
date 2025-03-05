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
    vector<int> leftSideView(TreeNode *root)
    {
        vector<int> ans;
        leftViewUtil(root, 0, ans);
        return ans;
    }
    void leftViewUtil(TreeNode *root, int level, vector<int> &res)
    {
        if (!root)
            return;
        // acts as a level tracker :
        if (level == res.size())
            res.push_back(root->val); // Store first node of each level
        leftViewUtil(root->left, level + 1, res);
        leftViewUtil(root->right, level + 1, res);
    }
};