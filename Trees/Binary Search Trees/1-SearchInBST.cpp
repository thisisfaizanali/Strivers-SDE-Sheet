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
// Recursive Code :
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {

        if (!root)
            return nullptr;
        // base case :
        if (val == root->val)
            return root;
        // if val is less than node : go left :
        if (val < root->val)
            return searchBST(root->left, val);
        // else : right
        return searchBST(root->right, val);
    }
};
// Iterative Code : uses constant O(1) space :
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // iterate until we reach the end :
        while (root)
        {
            // main condition :
            if (root->val == val)
                return root;
            // go left if val is smaller else go right :
            root = (val < root->val) ? root->left : root->right;
        }
        return nullptr;
    }
};