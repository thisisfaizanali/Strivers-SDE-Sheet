/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // Sort children's greed factors and cookie sizes in ascending order
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;    // Count of satisfied children
        int i = 0, j = 0; // Pointers for children's greed (i) and cookie sizes (j)

        // Iterate while both arrays have elements left to compare
        while (i < g.size() && j < s.size())
        {
            // If the current cookie can satisfy the current child's greed
            if (s[j] >= g[i])
            {
                count++; // Increment the count of satisfied children
                i++;     // Move to the next child
                j++;     // Move to the next cookie
            }
            else
            {
                j++; // If the cookie is too small, try the next larger cookie
            }
        }

        // Return the total number of satisfied children
        return count;
    }
};