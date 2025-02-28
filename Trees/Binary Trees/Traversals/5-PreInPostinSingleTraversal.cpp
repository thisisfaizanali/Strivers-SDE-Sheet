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
    vector<vector<int>> getTreeTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> pre, in, post;
        // stack -> {node, state}
        // state : 1 2 3 is basically position of root in these three traversals
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1}); // Push root with state 1 (preorder)
        while (!st.empty())
        {
            auto it = st.top();
            st.pop();

            if (it.second == 1)
            {
                pre.push_back(it.first->val);
                it.second++; // Move to next state
                st.push(it); // Push updated node back to stack

                if (it.first->left) // Push left child for further processing
                {
                    st.push({it.first->left, 1});
                }
            }
            else if (it.second == 2)
            {
                in.push_back(it.first->val);
                it.second++; // Move to next state
                st.push(it); // Push updated node back to stack

                if (it.first->right) // Push right child for further processing
                {
                    st.push({it.first->right, 1});
                }
            }
            else
            {
                post.push_back(it.first->val);
            }
        }
        ans.push_back(pre);
        ans.push_back(in);
        ans.push_back(post);
        return ans;
    }
};
