/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> rank, size, parent;

public:
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int upu = findUltimateParent(u);
        int upv = findUltimateParent(v);

        if (upu == upv)
            return;

        if (rank[upu] < rank[upv])
            parent[upu] = upv;

        else if (rank[upu] > rank[upv])
            parent[upv] = upu;

        else
        {
            parent[upu] = upv;
            rank[upv]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int upu = findUltimateParent(u);
        int upv = findUltimateParent(v);

        if (upu == upv)
            return;

        if (size[upu] < size[upv])
        {
            parent[upu] = upv;
            size[upv] += size[upu];
        }

        else
        {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // DSU but this ques is HARD to visualize :

        int n = accounts.size();
        // nodes are the names

        DSU ds(n); // initialize dsu

        //  Step 1 : Mark all emails with their node :
        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; ++i)
        {
            // first is name, mail starts from 1 column-wise :
            for (int j = 1; j < accounts[i].size(); ++j)
            {
                string mails = accounts[i][j];
                if (mapMailNode.find(mails) == mapMailNode.end())
                    mapMailNode[mails] = i;

                else // connect nodes with common mails :
                    ds.unionByRank(i, mapMailNode[mails]);
            }
        }

        // Step 2 : Merge the mails :
        vector<vector<string>> mergedMails(n);
        for (auto &it : mapMailNode)
        {
            string mail = it.first;
            // Merging occurs here :
            int node = ds.findUltimateParent(it.second); // if part of same component : ultimate parent will be the node (merged)
            mergedMails[node].push_back(mail);
        }

        // Step 3 : sort and prepare ans:

        vector<vector<string>> ans;
        for (int i = 0; i < n; ++i)
        {
            if (mergedMails[i].empty())
                continue; // case of merge and its initialized with n : so skip
            // sort the mails only :
            sort(mergedMails[i].begin(), mergedMails[i].end());
            // insert the name :
            mergedMails[i].insert(mergedMails[i].begin(), accounts[i][0]);
            // push to ans :
            ans.push_back(mergedMails[i]);
        }

        return ans;
    }
};