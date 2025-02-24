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
    vector<int> preorderTraversal(TreeNode *root)
    {
        // root,left,right -> this formula on subtrees
        vector<int> ans;
        preorderHelper(root, ans);
        return ans;
    }

private:
    void preorderHelper(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        preorderHelper(root->left, ans);
        preorderHelper(root->right, ans);
    }
};