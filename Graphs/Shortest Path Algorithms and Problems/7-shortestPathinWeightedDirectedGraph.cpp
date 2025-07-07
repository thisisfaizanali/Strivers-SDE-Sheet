/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Returns: [total_distance, path_node1, path_node2, ..., path_nodeN]
    // If no path exists, returns [-1]
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // n + 1 for creating adj, distance and parent
        // because nodes are from [1,n] :
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // Format: {distance_from_source, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 1}); // Starting from node 1 with distance 0

        vector<int> distance(n + 1, 1e9); // 1-based indexing
        distance[1] = 0;                  // Distance to source is 0

        //  Parent array to reconstruct the shortest path
        // Initially, each node is its own parent
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;

        // Dijkstra’s algorithm (using minHeap)
        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();

            int dist = top.first;  // Distance so far
            int node = top.second; // Current node being explored

            // Relax all the adjacent edges of the current node
            for (auto &neighbours : adj[node])
            {
                int neighbour = neighbours.first;
                int weight = neighbours.second;

                // If a shorter path to neighbour is found
                if (dist + weight < distance[neighbour])
                {
                    distance[neighbour] = dist + weight;            // Update distance
                    minHeap.push({distance[neighbour], neighbour}); // Push updated distance
                    parent[neighbour] = node;                       // Store parent for path reconstruction
                }
            }
        }

        //  If no path found from node 1 to node n
        if (distance[n] == 1e9)
            return {-1};

        //  Reconstruct the shortest path using parent[]
        vector<int> ans;
        int node = n; // we start from the end
        while (parent[node] != node)
        {
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1); // Include the start node

        //  Reverse the path to get it from 1 → n
        reverse(ans.begin(), ans.end());

        //  Insert total cost at the beginning
        ans.insert(ans.begin(), distance[n]);

        return ans;
    }
};
