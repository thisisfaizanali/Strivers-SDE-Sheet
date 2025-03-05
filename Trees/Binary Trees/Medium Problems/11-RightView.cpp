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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        RightView(root, 0, ans);
        return ans;
    }
    void RightView(TreeNode *root, int level, vector<int> &ans)
    {
        // Root Right Left :
        if (!root)
            return;
        // ans.size() acts as level tracker :
        if (level == ans.size())
            ans.push_back(root->val);
        RightView(root->right, level + 1, ans);
        RightView(root->left, level + 1, ans);
    }
};