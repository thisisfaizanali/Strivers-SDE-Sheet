/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
// Helper class to store information about each subtree
class NodeValue
{
public:
    int minVal, maxVal, maxSize;
    bool isBST;
    // Constructor to initialize values
    NodeValue(int minVal, int maxVal, int maxSize, bool isBST)
    {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
        this->isBST = isBST;
    }
};
class Solution
{
private:
    // Recursive function to find the largest BST in a binary tree
    NodeValue largestBSTHelper(Node *root, int &maxSize)
    {
        // Base case: If the node is NULL, return a default valid BST marker
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0, true);
        // Recursively process the left and right subtrees
        NodeValue left = largestBSTHelper(root->left, maxSize);
        NodeValue right = largestBSTHelper(root->right, maxSize);

        // Check if the current subtree satisfies BST properties
        if (left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal)
        {
            // Calculate the size of the current BST
            int currSize = left.maxSize + right.maxSize + 1;

            // Update the maximum BST size found so far
            maxSize = max(maxSize, currSize);

            // Return updated values for this subtree
            return NodeValue(
                min(root->data, left.minVal),  // Update min value of the subtree
                max(root->data, right.maxVal), // Update max value of the subtree
                currSize,                      // Size of the current BST
                true                           // This subtree is a valid BST
            );
        }
        // If the current subtree is not a BST, return an invalid marker
        return NodeValue(0, 0, 0, false);
    }

public:
    int largestBst(Node *root)
    {
        int maxSize = 0;
        largestBSTHelper(root, maxSize);
        return maxSize;
    }
};