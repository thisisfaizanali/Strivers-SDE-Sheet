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
        // use two stacks and their lifo nature
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> st1, st2;
        st1.push(root);
        // Push in first stack as : root left right
        //  Processing order bottom to top is : root right left
        while (!st1.empty())
        {
            root = st1.top();
            st1.pop();
            if (root->left)
                st1.push(root->left);
            if (root->right)
                st1.push(root->right);
            st2.push(root);
        }
        // Processing order top to bottom is : left right root
        while (!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};