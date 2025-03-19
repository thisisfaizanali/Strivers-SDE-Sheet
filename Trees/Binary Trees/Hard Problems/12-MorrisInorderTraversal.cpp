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
    vector<int> inorderTraversal(TreeNode *root)
    {
        // Morris Traversal(O(1) space but only for In and Pre) has three steps :
        // 1) If no left child : push curr node and move right
        // 2) If left child exists : find rightmost node of leftsubtree
        //  and make it point it to curr -> make a thread (TBT)
        // 3) When coming back remove the thread, push curr node and move right
        vector<int> inorder;
        if (!root)
            return inorder;
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left == nullptr)
            {
                // no left child : step 1
                inorder.push_back((curr->val));
                curr = curr->right;
            }
            else
            {
                // left child exists : step 2 and 3 :
                TreeNode *pred = curr->left;
                // step 2 : find pred and make thread
                while (pred->right && pred->right != curr)
                    pred = pred->right;
                if (pred->right == nullptr)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                // step 3 : when coming back remove thread
                else
                {
                    pred->right = nullptr;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};