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
    vector<int> bottomView(Node *root)
    {
        // same as top view except for one line :
        vector<int> ans;
        if (!root)
            return ans;
        map<int, int> mpp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            Node *node = p.first;
            int line = p.second;
            // Update the map every time we visit a node (we want the last node at this line)
            mpp[line] = node->data;
            if (node->left)
                q.push({node->left, line - 1});
            if (node->right)
                q.push({node->right, line + 1});
        }
        for (auto &x : mpp)
            ans.push_back(x.second);
        return ans;
    }
};