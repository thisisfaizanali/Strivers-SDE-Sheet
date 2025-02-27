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
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> st;
        while (true)
        {
            if (root)
            {
                // Push current node and move left
                st.push(root);
                root = root->left;
            }
            else
            {
                if (st.empty())
                    break; // Stop when all nodes are processed
                root = st.top();
                st.pop();
                ans.push_back(root->val); // Process node
                root = root->right;       // Move to right subtree
            }
        }
        return ans;
    }
};