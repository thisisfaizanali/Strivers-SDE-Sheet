/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
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
    int maxDepth(TreeNode *root)
    {
        // recursive code :
        if (!root)
            return 0;
        // This is postorder because height of subtress need to be calculated firt :
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        // Recurrence Relation based :
        return 1 + max(leftHeight, rightHeight);
    }
};