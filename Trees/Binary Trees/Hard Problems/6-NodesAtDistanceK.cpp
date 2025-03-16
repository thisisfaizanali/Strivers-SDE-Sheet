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
class Solution
{
public:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
    {
        // BFS to get parent of each node :
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if (node->right)
                {
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        // Conversion of BT to unidirected graph : BFS +  parent map
        // Radially outwards traversal : BFS + visited set
        unordered_map<TreeNode *, TreeNode *> parent;
        markParents(root, parent);
        unordered_set<TreeNode *> visited;
        queue<TreeNode *> q;
        // radial traversal from target :
        q.push(target);
        visited.insert(target);
        int distance = 0;
        while (!q.empty())
        {
            int size = q.size();
            // crucial part :
            if (distance == k)
                break;
            distance++;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left && !visited.count(node->left))
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.count(node->right))
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parent.count(node) && !visited.count(parent[node]))
                {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
        }
        // Extract the answer :
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};