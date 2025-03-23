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
class BSTIterator
{
private:
    stack<TreeNode *> stk;
    void pushLeft(TreeNode *node)
    {
        while (node)
        {
            stk.push(node);
            node = node->left;
        }
    }

public:
    // Constructor: Initialize iterator by pushing all left nodes from root
    BSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }

    // Returns the next smallest element in the BST
    int next()
    {
        TreeNode *node = stk.top(); // Get the top element (smallest available)
        stk.pop();                  // Remove it from stack
        // If the popped node has a right subtree, push its leftmost path
        if (node->right)
        {
            pushLeft(node->right);
        }
        return node->val; // Return the value of the next smallest element
    }
    // Returns true if there is a next smallest number in the BST
    bool hasNext()
    {
        return !stk.empty(); // If stack is not empty, there is a next element
    }
};
