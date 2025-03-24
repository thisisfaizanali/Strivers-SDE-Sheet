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
    void recoverTree(TreeNode *root)
    {
        // Optimal : Morris Inorder Traversal to get O(1) SC :
        TreeNode *first = NULL, *second = NULL, *prev = NULL, *curr = root;
        while (curr)
        {
            if (!curr->left)
            {
                // Process current node
                if (prev && prev->val > curr->val)
                {
                    if (!first)
                        first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right; // Move to the right subtree
            }
            else
            {
                // Find inorder predecessor
                TreeNode *pred = curr->left;
                while (pred->right && pred->right != curr)
                {
                    pred = pred->right;
                }
                // Create a temporary thread
                if (!pred->right)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    // Remove the thread and process the current node
                    pred->right = NULL;
                    if (prev && prev->val > curr->val)
                    {
                        if (!first)
                            first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right; // Move to the right subtree
                }
            }
        }
        // Swap the misplaced nodes to fix the BST
        if (first && second)
            swap(first->val, second->val);
    }
};
