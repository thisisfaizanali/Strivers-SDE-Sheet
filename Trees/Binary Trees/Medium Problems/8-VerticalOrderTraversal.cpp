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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // x-> vertical lines or horizontal distance from root
        // y-> levels/depth
        // Ordered map to store nodes sorted by (x, y)
        map<int, map<int, multiset<int>>> nodes;
        // Queue for BFS traversal (stores {node, {x, y}})
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}}); // Root starts at (0,0)
        // Level order traversal (BFS)
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int x = p.second.first, y = p.second.second;
            // Insert node value into the ordered map
            nodes[x][y].insert(node->val);
            // Push left and right children with updated coordinates
            if (node->left)
                q.push({node->left, {x - 1, y + 1}});
            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }
        // Extract results from sorted map structure
        vector<vector<int>> ans;
        // Iterate over x-coordinates
        for (auto &p : nodes)
        {
            vector<int> temp;
            // Iterate over y-coordinates
            for (auto &q : p.second)
            {
                temp.insert(temp.end(), q.second.begin(), q.second.end()); // Collect sorted values
            }
            ans.push_back(temp);
        }
        return ans;
    }
};