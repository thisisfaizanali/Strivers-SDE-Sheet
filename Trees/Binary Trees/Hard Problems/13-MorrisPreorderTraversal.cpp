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
    vector<int> preorderTraversal(TreeNode *root)
    {
        // Morris Traversal (O(1) space but only for Inorder and Preorder) has three steps:
        // 1) If no left child: push curr node and move right
        // 2) If left child exists: find rightmost node of left subtree
        //    and make it point to curr -> make a thread (TBT)
        // 3) When coming back, remove the thread and move right
        vector<int> preorder;
        if (!root)
            return preorder;
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left == nullptr)
            {
                // No left child: Step 1
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                // Left child exists: Step 2 and 3
                TreeNode *pred = curr->left;
                // Step 2: Find predecessor and make thread
                while (pred->right && pred->right != curr)
                    pred = pred->right;
                if (pred->right == nullptr)
                {
                    pred->right = curr;
                    // Preorder visit before moving left
                    // because in pre -> root comes first or curr :
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                // Step 3: When coming back, remove thread
                else
                {
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};
