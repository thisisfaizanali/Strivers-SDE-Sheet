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
    // For height do not use recursion :
    int leftHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->left;
        }
        return height;
    }
    int rightHeight(TreeNode *root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->right;
        }
        return height;
    }
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int leftSubtreeHeight = leftHeight(root);
        int rightSubtreeHeight = rightHeight(root);
        // CBT property:
        if (leftSubtreeHeight == rightSubtreeHeight)
            return (1 << leftSubtreeHeight) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};