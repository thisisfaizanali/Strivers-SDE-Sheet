/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // Dijktstra
        // Steps vary by 1 so no need of pq : use a queue
        // mod value is 1e5 so nodes as a result of multiplication and % by 1e5:
        // can range from [0,9999] : (MOST IMPORTANT PART)

        queue<pair<int, int>> q; // {node,distance}
        q.push({start, 0});

        vector<int> distance(1e5, 1e9);
        distance[start] = 0;

        const int MOD = 1e5;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int node = it.first;
            int steps = it.second;

            // Do the multiplication and division :
            for (auto &x : arr)
            {
                int num = (node * x) % MOD;

                if (steps + 1 < distance[num])
                {
                    // Relax the edges :
                    distance[num] = steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }

        return distance[end] == 1e9 ? -1 : distance[end];
    }
};
