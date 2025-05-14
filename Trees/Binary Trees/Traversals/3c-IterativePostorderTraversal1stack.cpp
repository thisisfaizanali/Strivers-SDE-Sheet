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
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *curr = root;    // For traversal down the tree
        TreeNode *temp = nullptr; // Tracks the last visited node

        while (curr != nullptr || !st.empty())
        {
            if (curr != nullptr)
            {
                // Go as far left as possible
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                // We're done going left — now check the right subtree
                temp = st.top()->right;

                // Either:
                // - It has no right child, or
                // - Its right child was already visited
                if (temp == nullptr)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    // Keep checking if we’re coming back up from a right child
                    // If so, the parent is now ready to be processed
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    // Right child exists and hasn’t been visited yet — go there
                    curr = temp;
                }
            }
        }

        return ans;
    }
};
