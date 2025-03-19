/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
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
// Recursive approach :
class Solution
{
public:
    TreeNode *prev = nullptr;
    void flatten(TreeNode *root)
    {
        // right, left and root :
        // use prev :
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
};
// Iterative approach using Stack :
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);
            if (!st.empty())
                curr->right = st.top();
            curr->left = nullptr;
        }
    }
};
// Morris Traversal :
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        // slight modification of Morris Traversal :
        TreeNode *curr = root;
        while (curr)
        {
            // If there is a left subtree, we need to move it to the right
            if (curr->left)
            {
                TreeNode *prev = curr->left;
                // Find the rightmost node in the left subtree (predecessor)
                while (prev->right)
                    prev = prev->right;
                // Connect the rightmost node of the left subtree to the original right subtree
                prev->right = curr->right;
                // Move the left subtree to the right
                curr->right = curr->left;
                curr->left = nullptr; // Set left to null since we are flattening
            }
            // Move to the next right node
            curr = curr->right;
        }
    }
};