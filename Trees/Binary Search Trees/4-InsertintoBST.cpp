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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // If the tree is empty, create a new node and return it
        if (!root)
            return new TreeNode(val);
        TreeNode *curr = root;
        // To keep track of the parent node as curr will point to nullptr after while loop finishes :
        TreeNode *parent = nullptr;
        while (curr)
        {
            parent = curr;
            if (curr->val < val)
            {
                // Move right if the value is greater
                curr = curr->right;
            }
            else
            {
                // Move left if the value is smaller or equal
                curr = curr->left;
            }
        }
        // Insert the new node as a left or right child of the parent
        if (parent->val < val)
            parent->right = new TreeNode(val);
        else
            parent->left = new TreeNode(val);
        return root; // Return the modified tree
    }
};
