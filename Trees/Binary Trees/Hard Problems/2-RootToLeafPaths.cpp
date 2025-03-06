/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
/*+++++++++++++++++++++++++++++++ GFG ques +++++++++++++++++++++++++++++++++*/
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
class Solution
{
public:
    vector<vector<int>> rootToLeafPaths(Node *root)
    {
        vector<vector<int>> result;
        vector<int> currentPath;
        findPaths(root, currentPath, result);
        return result;
    }

private:
    void findPaths(Node *root, vector<int> &currentPath, vector<vector<int>> &result)
    {
        if (!root)
            return; // Base case: If node is NULL, return

        currentPath.push_back(root->data); // Add current node to the path

        // If it's a leaf node, store the path
        if (!root->left && !root->right)
        {
            result.push_back(currentPath);
        }
        else
        {
            // Recur for left and right subtrees
            findPaths(root->left, currentPath, result);
            findPaths(root->right, currentPath, result);
        }

        // Backtrack: Remove last node after returning from recursion
        currentPath.pop_back();
    }
};
/*++++++++++++++++++++++++++++++++++ LeetCode ques +++++++++++++++++++++++++++++++ */
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        if (!root)
            return result;
        string path;
        dfs(root, path, result);
        return result;
    }

private:
    void dfs(TreeNode *node, string path, vector<string> &result)
    {
        if (!node)
            return;

        // Append "->" separator if the path already has elements
        if (!path.empty())
            path += "->";

        // Convert current node value to string and add to path
        path += to_string(node->val);

        // If it's a leaf node, store the completed path in the result vector
        if (!node->left && !node->right)
        {
            result.push_back(path);
        }
        else
        {
            // Recursively call DFS on left and right children
            dfs(node->left, path, result);
            dfs(node->right, path, result);
        }
    }
};
