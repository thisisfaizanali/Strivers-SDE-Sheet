/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// leetcode version :
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        // follow up of course schedule 1 or pre-requisite tasks :

        // find ordering of tasks to finish all tasks : just return topo array using Kahn

        // return any order if possible otherwise empty array :

        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites)
            // prerequisites[i] = [a, b] means: to take course a, you must first take course b
            // So, add an edge from b → a (b must come before a)
            adj[p[1]].push_back(p[0]);

        vector<int> indegree(numCourses, 0);
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
            return topo;

        return {};
    }
};

// gfg version :
class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites)
    {
        // follow up of course schedule 1 or pre-requisite tasks :

        // find ordering of tasks to finish all tasks : just return topo array using Kahn

        // return any order if possible otherwise empty array :

        vector<vector<int>> adj(n);
        for (auto &p : prerequisites)
            // prerequisites[i] = [a, b] means: to take course a, you must first take course b
            // So, add an edge from b → a (b must come before a)
            adj[p[1]].push_back(p[0]);

        vector<int> indegree(n, 0);

        for (int u = 0; u < n; ++u)
        {
            for (auto &v : adj[u])
                indegree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < n; ++i)
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

        if (topo.size() == n)
            return topo;

        return {};
    }
};
