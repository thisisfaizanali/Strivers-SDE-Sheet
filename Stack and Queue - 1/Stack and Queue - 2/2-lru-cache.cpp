/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class LRUCache
{
    // making of dll and constructor with key and value :
    class node
    {
    public:
        int key;
        int value;
        node *next;
        node *prev;
        node(int _key, int _value)
        {
            key = _key;
            value = _value;
        }
    };
    // dummy tail and dummy head :
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    int cap;                      // capacity
    unordered_map<int, node *> m; // map with key and value
    void addnode(node *newnode)
    {
        // not following normal ll or dll procedure: because of dummies
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deletenode(node *delnode)
    {
        // not following normal ll or dll procedure: because of dummies
        node *delnext = delnode->next;
        node *delprev = delnode->prev;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    int get(int key)
    {
        // if key is present
        if (m.find(key) != m.end())
        {
            node *resnode = m[key];
            int res = resnode->value;
            // delete it :
            m.erase(key);
            deletenode(resnode);
            // create it at the front :
            addnode(resnode);
            m[key] = head->next; // actual head (front)
            return res;
        }
        // if not :
        return -1;
    }
    void put(int key, int value)
    {
        // present :
        if (m.find(key) != m.end())
        {
            node *exist = m[key];
            m.erase(key);
            deletenode(exist);
        }
        // capacity matched :
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        // create a new node at beginning :
        addnode(new node(key, value));
        m[key] = head->next;
    }
};
