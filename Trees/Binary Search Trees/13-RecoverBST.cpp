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
private:
    // prev is used to traverse  :
    TreeNode *first, *middle, *last, *prev;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        // Left subtree
        inorder(root->left);
        // Detect swapped nodes
        if (prev && root->val < prev->val)
        {
            // First violation
            if (!first)
            {
                first = prev;
                middle = root;
            }
            // Second violation
            else
            {
                last = root;
            }
        }
        prev = root;
        // Right subtree
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = middle = last = prev = NULL;
        inorder(root);
        // Swap the misplaced nodes
        if (first && last)
            swap(first->val, last->val); // Non-adjacent nodes
        else if (first && middle)
            swap(first->val, middle->val); // Adjacent nodes
    }
};
