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
// Iterator for BST to support both inorder (left-to-right) and reverse inorder (right-to-left)
class BSTiterator
{
private:
    stack<TreeNode *> st;
    bool reverse; // Flag (false = inorder, true = reverse inorder)
public:
    // Constructor initializes the iterator and pushes nodes of the given direction
    BSTiterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushNodes(root);
    }
    // Returns the next element in the traversal order
    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        // If normal inorder, move to the right subtree; if reverse, move to the left subtree
        if (!reverse)
            pushNodes(node->right);
        else
            pushNodes(node->left);
        return node->val;
    }
    // Checks if there are more elements to traverse
    bool hasNext()
    {
        return !st.empty();
    }

private:
    // Pushes nodes into the stack following the specified traversal direction
    void pushNodes(TreeNode *node)
    {
        while (node)
        {
            st.push(node);
            node = reverse ? node->right : node->left; // Move right for reverse inorder, left for normal inorder
        }
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;

        // - `left` for normal inorder traversal (smallest to largest)
        // - `right` for reverse inorder traversal (largest to smallest)
        BSTiterator left(root, false);
        BSTiterator right(root, true);
        // Get the first smallest and largest elements
        int i = left.next();
        int j = right.next();
        // Use two-pointer approach to find if two elements sum to k
        while (i < j)
        {
            int sum = i + j;
            if (sum == k)
                return true; // Found the required pair
            else if (sum < k)
                i = left.next(); // Increase sum by moving left iterator forward
            else
                j = right.next(); // Decrease sum by moving right iterator backward
        }
        return false; // No such pair found
    }
};
