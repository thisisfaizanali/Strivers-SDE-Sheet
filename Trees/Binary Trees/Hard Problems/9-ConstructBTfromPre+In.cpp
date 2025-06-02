/*++++++++++++++++++++++++++++++++++++++++++++++++++++++Bismillah+++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        // Step 1: Map each value in inorder to its index
        // Why? So we can find root position in O(1) instead of O(n) each time
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; ++i)
            inMap[inorder[i]] = i;
        // Step 2: Start recursive tree building
        return buildSubTree(preorder, 0, n - 1, inorder, 0, n - 1, inMap);
    }

private:
    TreeNode *buildSubTree(vector<int> &preorder, int preStart, int preEnd,
                           vector<int> &inorder, int inStart, int inEnd,
                           unordered_map<int, int> &inMap)
    {
        // Step 3: Base case — invalid range means no nodes to process
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;
        // Step 4: The first element in preorder is always the root of the subtree
        TreeNode *root = new TreeNode(preorder[preStart]);
        // Step 5: Find index of root in inorder using the map
        int inRoot = inMap[root->val];
        // Step 6: Count of nodes in the left subtree
        int numsLeft = inRoot - inStart;
        // Step 7: Build left subtree
        // preorder:
        //   - Start from preStart + 1 (next after root)
        //   - End at preStart + numsLeft (covers left subtree)
        // inorder:
        //   - Start from inStart
        //   - End at inRoot - 1 (left part before root)
        root->left = buildSubTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
        // Step 8: Build right subtree
        // preorder:
        //   - Start from preStart + numsLeft + 1 (skip root + left subtree)
        //   - End at preEnd
        // inorder:
        //   - Start from inRoot + 1 (right part after root)
        //   - End at inEnd
        root->right = buildSubTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
        return root;
    }
};
