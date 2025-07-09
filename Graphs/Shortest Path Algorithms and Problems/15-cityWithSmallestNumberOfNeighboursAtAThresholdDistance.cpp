/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// LeetCode version :
class Solution
{
public:
    // Distance from one city to every other city : USE FLOYD WARSHALL
    // check condition and return answer
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Distance from a city to itself is 0
        for (int i = 0; i < n; ++i)
            dist[i][i] = 0;

        for (auto &e : edges)
        {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        // Floyd-Warshall Algorithm to compute all-pairs shortest paths
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int cityCount = n;   // Minimum reachable cities found so far
        int cityNumber = -1; // Result city index

        // Count reachable cities for each city within the threshold
        for (int city = 0; city < n; ++city)
        {
            int count = 0;

            for (int adjCity = 0; adjCity < n; ++adjCity)
            {
                if (city != adjCity && dist[city][adjCity] <= distanceThreshold)
                {
                    count++;
                }
            }

            // Update result if current city has fewer or equal reachable cities
            // (prefer higher index in case of tie)
            if (count <= cityCount)
            {
                cityCount = count;
                cityNumber = city;
            }
        }

        return cityNumber;
    }
};

// gfg version :
class Solution
{
public:
    // Distance from one city to every other city : USE FLOYD WARSHALL
    // check condition and return answer
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Distance from a city to itself is 0
        for (int i = 0; i < n; ++i)
            dist[i][i] = 0;

        for (auto &e : edges)
        {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        // Floyd-Warshall Algorithm to compute all-pairs shortest paths
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int cityCount = n;   // Minimum reachable cities found so far
        int cityNumber = -1; // Result city index

        // Count reachable cities for each city within the threshold
        for (int city = 0; city < n; ++city)
        {
            int count = 0;

            for (int adjCity = 0; adjCity < n; ++adjCity)
            {
                if (city != adjCity && dist[city][adjCity] <= distanceThreshold)
                {
                    count++;
                }
            }

            // Update result if current city has fewer or equal reachable cities
            // (prefer higher index in case of tie)
            if (count <= cityCount)
            {
                cityCount = count;
                cityNumber = city;
            }
        }

        return cityNumber;
    }
};
