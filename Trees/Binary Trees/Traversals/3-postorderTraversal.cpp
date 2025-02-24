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
    vector<int> postorderTraversal(TreeNode *root)
    {
        // left,right,root -> this formula on subtrees
        vector<int> ans;
        postorderHelper(root, ans);
        return ans;
    }
    void postorderHelper(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        postorderHelper(root->left, ans);
        postorderHelper(root->right, ans);
        ans.push_back(root->val);
    }
};