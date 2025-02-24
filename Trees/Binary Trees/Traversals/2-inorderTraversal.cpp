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
    vector<int> inorderTraversal(TreeNode *root)
    {
        // left,root,right -> this formula on subtrees
        vector<int> ans;
        inorderHelper(root, ans);
        return ans;
    }
    void inorderHelper(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        inorderHelper(root->left, ans);
        ans.push_back(root->val);
        inorderHelper(root->right, ans);
    }
};