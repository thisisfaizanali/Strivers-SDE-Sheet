/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Dijkstra does not work for negative weights on edges :
    // As it will lead to a infinite loop
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // make adjacency list :
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // distance array :
        vector<int> distance(V, 1e9);
        // mark source as 0 :
        distance[src] = 0;

        // set : {distance, node}
        // acts like minHeap but allows faster deletion
        set<pair<int, int>> st;

        st.insert({0, src}); // insert distance from src to src and src

        while (!st.empty())
        {
            auto top = *(st.begin());
            st.erase(st.begin());

            int dist = top.first;  // distance from src to popped node
            int node = top.second; // popped node

            for (auto &neighbours : adj[node])
            {
                int neighbour = neighbours.first;
                int weight = neighbours.second;

                // greedily find shortest distance :
                // (Relax the edges)
                if (dist + weight < distance[neighbour])
                {
                    // if neighbour already in set with greater dist, erase it
                    if (distance[neighbour] != 1e9)
                    {
                        st.erase({distance[neighbour], neighbour});
                    }

                    distance[neighbour] = dist + weight;
                    // insert new shorter path
                    st.insert({distance[neighbour], neighbour});
                }
            }
        }

        return distance; // stores answer
    }
};
