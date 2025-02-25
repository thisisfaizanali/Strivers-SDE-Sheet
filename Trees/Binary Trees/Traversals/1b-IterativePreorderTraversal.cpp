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
        vector<int> preorderTraversal; // to store the ans
        // Edge case : if empty -> return empty
        if (root == nullptr)
            return preorderTraversal;
        stack<TreeNode *> st; // to simulate recursion
        st.push(root);        // push root node
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            preorderTraversal.push_back(node->val); // store current node value
            // Push right before first because of stack's LIFO nature
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return preorderTraversal;
    }
};