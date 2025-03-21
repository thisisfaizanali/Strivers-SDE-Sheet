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
    void inorder(TreeNode *root, int &k, int &result)
    {

        if (!root)
            return;
        inorder(root->left, k, result); // go left
        if (--k == 0)
        {
            // decrement k and if it becomes 0, we have our node :
            result = root->val;
            return;
        }
        // go right
        inorder(root->right, k, result);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int result = -1;
        // inorder for BST will always return in ascending sorted order
        inorder(root, k, result);
        return result;
    }
};
