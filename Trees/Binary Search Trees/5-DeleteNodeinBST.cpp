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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;
        // If the key is smaller, move to the left subtree
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        // If the key is larger, move to the right subtree
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        // If key matches, we found the node to delete
        else
        {
            // Case 1: No left child → Replace with right child
            if (!root->left)
                return root->right;
            // Case 2: No right child → Replace with left child
            if (!root->right)
                return root->left;
            // Case 3: Node has both left and right children
            // Find the inorder predecessor (rightmost node in left subtree)
            TreeNode *pred = root->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            // Attach the right subtree of the deleted node to the inorder predecessor
            pred->right = root->right;
            // Replace current node with its left child (new subtree root)
            return root->left;
        }
        // Return the (possibly updated) root node to the previous recursive call
        return root;
    }
};
