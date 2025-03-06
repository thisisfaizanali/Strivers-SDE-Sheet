/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
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
    vector<int> rootToNodePath(TreeNode *root, int target)
    {
        // backtracking + bool + ds + preorder
        vector<int> ans;
        getPath(root, target, ans);
        return ans;
    }

private:
    bool getPath(TreeNode *root, int target, vector<int> &ans)
    {
        if (!root)
            return false; // Base case: If the node is NULL, return false

        ans.push_back(root->val); // Add the current node to the path

        if (root->val == target)
            return true; // If target is found, return true

        // Recur for left and right subtrees
        if (getPath(root->left, target, ans) || getPath(root->right, target, ans))
            return true;

        // If target not found in this path, backtrack (remove last element)
        ans.pop_back();
        return false;
    }
};
