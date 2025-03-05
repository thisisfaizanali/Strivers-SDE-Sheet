/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        // {vertical lines  : value of node}
        map<int, int> mpp;
        //{node, vertical lines}
        queue<pair<Node *, int>> q;
        q.push({root, 0}); // Root node with HD = 0
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            Node *node = p.first;
            int line = p.second;
            // If horizontal distance is encountered for the first time, store node value
            if (mpp.find(line) == mpp.end())
            {
                mpp[line] = node->data;
            }
            // Push left child with updated HD
            if (node->left)
                q.push({node->left, line - 1});
            // Push right child with updated HD
            if (node->right)
                q.push({node->right, line + 1});
        }
        // Extract values in sorted order of horizontal distance
        for (auto &x : mpp)
            ans.push_back(x.second);
        return ans;
    }
};
