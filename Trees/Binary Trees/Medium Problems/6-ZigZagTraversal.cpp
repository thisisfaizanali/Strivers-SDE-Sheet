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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = true; // true -> left to right, false -> right to left
        while (!q.empty())
        {
            int size = q.size();
            vector<int> temp(size); // Store current level nodes
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                // Determine correct position based on zigzag flag
                int index = flag ? i : (size - i - 1);
                temp[index] = node->val;
                // Always push children in normal left-to-right order
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.push_back(temp); // Add current level to result
            flag = !flag;        // Flip direction for next level
        }
        return ans;
    }
};
