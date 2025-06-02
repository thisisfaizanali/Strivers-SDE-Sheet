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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        // Step 1: Map each value in inorder to its index
        // Why? So we can find root position in O(1) instead of O(n) each time
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; ++i)
            inMap[inorder[i]] = i;
        // Step 2: Start recursive tree building
        return buildSubTree(inorder, 0, n - 1, postorder, 0, n - 1, inMap);
    }

private:
    TreeNode *buildSubTree(vector<int> &inorder, int inStart, int inEnd,
                           vector<int> &postorder, int postStart, int postEnd,
                           unordered_map<int, int> &inMap)
    {
        // Step 3: Base case — invalid range means no nodes to process
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;
        // Step 4: The last element in postorder is always the root of the subtree
        TreeNode *root = new TreeNode(postorder[postEnd]);
        // Step 5: Find index of root in inorder using the map
        int inRoot = inMap[root->val];
        // Step 6: Count of nodes in the left subtree
        int numsLeft = inRoot - inStart;
        // Step 7: Build left subtree
        // inorder:
        //   - Start from inStart
        //   - End at inRoot - 1 (left part before root)
        // postorder:
        //   - Start from postStart
        //   - End at postStart + numsLeft - 1 (covers left subtree)
        root->left = buildSubTree(inorder, inStart, inRoot - 1,
                                  postorder, postStart, postStart + numsLeft - 1, inMap);
        // Step 8: Build right subtree
        // inorder:
        //   - Start from inRoot + 1 (right part after root)
        //   - End at inEnd
        // postorder:
        //   - Start from postStart + numsLeft
        //   - End at postEnd - 1 (skip root which is at postEnd)
        root->right = buildSubTree(inorder, inRoot + 1, inEnd,
                                   postorder, postStart + numsLeft, postEnd - 1, inMap);
        return root;
    }
};
