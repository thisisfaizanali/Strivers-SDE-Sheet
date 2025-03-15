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
    int widthOfBinaryTree(TreeNode *root)
    {
        // Level Order Traversal
        if (!root)
            return 0;
        // queue : {node, index}
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while (!q.empty())
        {
            int size = q.size();
            int indexOfFirstNodeOfLevel, indexOfLastNodeOfLevel;
            // used for normalization of indices :
            int minIndexOfLevel = q.front().second;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front().first;
                // normalization of Indices:
                int currIndex = q.front().second - minIndexOfLevel;
                q.pop();
                // Store the first and last index at the current level
                if (i == 0)
                    indexOfFirstNodeOfLevel = currIndex;
                if (i == size - 1)
                    indexOfLastNodeOfLevel = currIndex;

                // Enqueue left and right children with their respective indices
                if (node->left)
                    q.push({node->left, currIndex * 2 + 1});
                if (node->right)
                    q.push({node->right, currIndex * 2 + 2});
            }
            // Update maxWidth with the width of the current level
            maxWidth = max(maxWidth, indexOfLastNodeOfLevel - indexOfFirstNodeOfLevel + 1);
        }
        return maxWidth;
    }
};
