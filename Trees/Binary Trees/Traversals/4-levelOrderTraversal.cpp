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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans; // stores the answer
        if (root == nullptr)
            return ans;      // return empty if tree is empty
        queue<TreeNode *> q; // for bfs traversal
        q.push(root);        // push root node
        while (!q.empty())
        {
            int size = q.size(); // number of nodes at current level
            vector<int> level;   // stores values of nodes at current level
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop(); // remove processed node
                if (node->left)
                    q.push(node->left); // push left child if it exists
                if (node->right)
                    q.push(node->right);    // push right child if it exists
                level.push_back(node->val); // store current node's value
            }
            ans.push_back(level); // add level to final answer
        }
        return ans;
    }
};