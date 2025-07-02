/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// leetcode version :
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // reminds me of Topological Sorting
        // i will use : Kahn's algorithm

        // if it can be done for all nodes then yes possible otherwise false

        // or we can just check for cycle using DFS

        // This problem boils down to say whether a DAG can be formed or not :

        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
            // Note: Using a → b works here because we are only detecting cycles (not generating order)
            // But the correct semantic direction is: b → a (b must come before a)
            adj[p[0]].push_back(p[1]);

        vector<int> indegree(numCourses);
        for (int u = 0; u < numCourses; ++u)
        {
            for (auto &v : adj[u])
                indegree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

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

        if (topo.size() == numCourses)
            return true; // topo sorting done for all courses

        return false;
    }
};

// gfg version :
class Solution
{
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        // reminds me of Topological Sorting
        // i will use : Kahn's algorithm

        // if it can be done for all nodes then yes possible otherwise false

        // or we can just check for cycle using DFS

        // This problem boils down to say whether a DAG can be formed or not :

        vector<vector<int>> adj(N);
        for (auto &p : prerequisites)
            // Note: Using a → b works here because we are only detecting cycles (not generating order)
            // But the correct semantic direction is: b → a (b must come before a)
            adj[p.first].push_back(p.second);

        vector<int> indegree(N);

        for (int u = 0; u < N; ++u)
        {
            for (auto &v : adj[u])
                indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < N; ++i)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> top;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            top.push_back(node);

            for (auto &neighbour : adj[node])
            {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        if (top.size() == N)
            return true; // topo sorting done for all N tasks

        return false;
    }
};
