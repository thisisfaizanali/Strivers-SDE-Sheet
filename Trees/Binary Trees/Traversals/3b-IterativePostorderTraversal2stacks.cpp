/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
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
        if (!root)
            return ans;
        stack<TreeNode *> st1, st2;
        st1.push(root);
        // st1 simulates modified preorder traversal: root -> right -> left
        // This is achieved by pushing left before right (because stack is LIFO)
        while (!st1.empty())
        {
            root = st1.top();
            st1.pop();
            st2.push(root); // root is visited before its children
            if (root->left) // left is pushed first
                st1.push(root->left);
            if (root->right) // right is pushed after left, so it is processed first
                st1.push(root->right);
        }
        // st2 contains nodes in reverse postorder: root → right → left
        // Reversing this by popping gives: left → right → root (i.e., postorder)
        while (!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};
