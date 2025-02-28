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
        TreeNode *curr = root;    // Pointer for traversal
        TreeNode *temp = nullptr; // Temporary pointer to track last visited node
        while (curr != nullptr || !st.empty())
        {
            if (curr != nullptr)
            {
                st.push(curr); // Push current node and move left
                curr = curr->left;
            }
            else
            {
                temp = st.top()->right; // Get the right child of the top node

                if (temp == nullptr) // If no right child, process current node
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);

                    // Process parent nodes whose right subtree is already visited
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    curr = temp; // Move to right subtree if unvisited
                }
            }
        }
        return ans;
    }
};
