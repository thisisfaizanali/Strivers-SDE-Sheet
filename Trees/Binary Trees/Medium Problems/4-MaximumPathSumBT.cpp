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
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN; // INT_MIN helps in all negative tree
        dfsSum(root, maxSum);
        return maxSum;
    }

    int dfsSum(TreeNode *root, int &maxSum)
    {
        if (!root)
            return 0; // Base case: return 0 for null nodes
        // Recursively find max path sum from left and right subtrees, ignoring negative sums
        int leftSum = max(0, dfsSum(root->left, maxSum));
        int rightSum = max(0, dfsSum(root->right, maxSum));
        // Update maxSum considering the path passing through the current node
        maxSum = max(maxSum, leftSum + rightSum + root->val);
        // main part :
        return root->val + max(leftSum, rightSum);
    }
};
