/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    int minTime(Node *root, int target)
    {
        // bt to ug and find target node :
        unordered_map<Node *, Node *> parent;
        Node *targetNode = nullptr;
        markParent(root, parent, targetNode, target);
        queue<Node *> q;
        // visited set :
        unordered_set<Node *> visited;
        q.push(targetNode);
        visited.insert(targetNode);
        int time = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                Node *node = q.front();
                q.pop();
                if (node->left && !visited.count(node->left))
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.count(node->right))
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parent[node] && !visited.count(parent[node]))
                {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
            }
            time++;
        }
        return time - 1; // while loop condition is checked at start, that's why -1
        // alternatively use a flag
    }

private:
    Node *findNode(Node *root, int target)
    {
        if (!root)
            return nullptr;
        if (root->data == target)
            return root;
        Node *leftSearch = findNode(root->left, target);
        if (leftSearch)
            return leftSearch;
        else
            return findNode(root->right, target);
    }

private:
    void markParent(Node *root, unordered_map<Node *, Node *> &parent, Node *&targetNode, int target)
    {
        // mark Parent and find target Node :
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                Node *node = q.front();
                q.pop();
                if (node->data == target)
                    targetNode = node;
                if (node->left)
                {
                    q.push(node->left);
                    parent[node->left] = node;
                }
                if (node->right)
                {
                    q.push(node->right);
                    parent[node->right] = node;
                }
            }
        }
    }
};