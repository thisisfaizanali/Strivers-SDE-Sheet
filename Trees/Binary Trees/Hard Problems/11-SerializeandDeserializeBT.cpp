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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        // serialize means converting to string :
        //  we will use bfs :
        if (!root)
            return "";
        queue<TreeNode *> q;
        q.push(root);
        string result = "";
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node)
                {
                    result.append(to_string(node->val) + ',');
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                {
                    // # is for null nodes :
                    result.append("#,");
                }
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // deserialize means converting back to tree :
        //  we will use bfs :
        // we also need to use stringstream + getline :
        if (data.empty())
            return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        queue<TreeNode *> q;
        // construct the new node :
        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                if (getline(s, str, ',') && str != "#")
                {
                    // node's left points to new node we make :
                    node->left = new TreeNode(stoi(str));
                    q.push(node->left);
                }
                if (getline(s, str, ',') && str != "#")
                {
                    // node's right points to new node we make :
                    node->right = new TreeNode(stoi(str));
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};