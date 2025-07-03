/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// available on gfg for free but paid question on leetcode :
class Solution
{
public:
    string findOrder(vector<string> &words)
    {
        int V = 26; // Total lowercase English letters

        // Graph adjacency list for 26 letters
        vector<vector<int>> adj(V);

        // Indegree array to support Kahn's algorithm (BFS Topo Sort)
        vector<int> indegree(V, 0);

        // Track which characters are present in the input
        vector<int> present(V, 0);

        // Mark all characters that appear in the input words
        for (auto &word : words)
        {
            for (auto &letter : word)
            {
                present[letter - 'a'] = 1;
            }
        }

        // Build the graph by comparing adjacent word pairs
        for (int i = 0; i < words.size() - 1; ++i)
        {
            string &s1 = words[i];
            string &s2 = words[i + 1];

            // Edge case: s1 is longer and is a prefix of s2 → invalid order
            if (s1.size() > s2.size() && s1.substr(0, s2.size()) == s2)
                return "";

            int len = min(s1.size(), s2.size());

            // Find first differing character and create a directed edge
            for (int j = 0; j < len; ++j)
            {
                if (s1[j] != s2[j])
                {
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';
                    adj[u].push_back(v);
                    indegree[v]++;
                    break; // Only first mismatch matters
                }
            }
        }

        // Initialize queue with nodes having zero indegree (sources)
        queue<int> q;
        for (int i = 0; i < V; ++i)
        {
            if (present[i] == 1 && indegree[i] == 0)
                q.push(i);
        }

        // Perform Kahn's Algorithm for Topological Sort
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto &neighbour : adj[node])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        // If topo sort doesn't include all present characters → cycle detected
        if (topo.size() != count(present.begin(), present.end(), 1))
            return "";

        // Convert topological order from indices to characters
        string ans = "";
        for (auto &number : topo)
        {
            ans += static_cast<char>(number + 'a');
        }

        return ans;
    }
};
