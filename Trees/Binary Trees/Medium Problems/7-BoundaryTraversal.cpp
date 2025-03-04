/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
class Solution
{
public:
    bool isLeaf(Node *root)
    {
        // root should exist but not left and right :
        if (!root)
            return false;
        return !root->left && !root->right;
    }
    void addLeftBoundary(Node *root, vector<int> &ans)
    {
        Node *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr)) // Ignore leaf nodes
                ans.push_back(curr->data);
            curr = (curr->left) ? curr->left : curr->right; // Move to left child, else right
        }
    }
    void addLeaves(Node *root, vector<int> &ans)
    {
        // preorder inorder all will work :
        // here its preorder  : root,left,right
        if (!root)
            return;
        if (isLeaf(root))
            ans.push_back(root->data);
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }
    void addRightBoundary(Node *root, vector<int> &ans)
    {
        Node *curr = root->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr)) // Ignore leaf nodes
                temp.push_back(curr->data);
            curr = (curr->right) ? curr->right : curr->left; // Move to right child, else left
        }
        ans.insert(ans.end(), temp.rbegin(), temp.rend()); // Reverse and add to result
    }
    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        if (!isLeaf(root)) // Add root if it's not a leaf
            ans.push_back(root->data);
        addLeftBoundary(root, ans);  // Process left boundary
        addLeaves(root, ans);        // Process leaf nodes
        addRightBoundary(root, ans); // Process right boundary
        return ans;
    }
};
