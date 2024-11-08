/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define eb emplace_back
#define all(p) p.begin(), p.end()
#define idx size_t
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    bool graphColoring(int v, vector<pair<int, int>> &edges, int m)
    {
        // v vertices = n nodes
        // creating a graph using the edges list
        //  in the form of adjacency matrix
        vector<vector<bool>> graph(v, vector<bool>(v, false));
        for (auto &edge : edges)
        {
            int u = edge.first;
            int v = edge.second;
            graph[u][v] = true;
            graph[v][u] = true;
        }
        // color array for marking and unmarking
        vector<int> color(v, 0);
        // back tracking function
        return solve(0, color, v, graph, m);
    }
    bool solve(int nodes, vector<int> &color, int v, vector<vector<bool>> &graph, int m)
    {
        if (nodes >= v)
        {
            return true;
        }
        // let us try out colors
        for (int i = 1; i <= m; ++i)
        {
            // if safe to fill in color
            if (isSafe(nodes, i, color, v, graph, m) == true)
            {
                color[nodes] = i;                                 // cause we color nodes
                if (solve(nodes + 1, color, v, graph, m) == true) // further recurive call
                {
                    return true;
                }
                color[nodes] = 0; // back track
            }
        }
        return false; // if could not be colored
    }
    bool isSafe(int nodes, int col, vector<int> &color, int v, vector<vector<bool>> &graph, int m)
    {
        // checking for all vertices
        for (int k = 0; k < v; ++k)
        // from 0 to v-1 because we dont check for current node but rather adjacent nodes
        {
            if (k != nodes && graph[k][nodes] && color[k] == col)
            {
                return false;
                // unsafe to color
            }
        }
        return true; // safe to color
    }
};