/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        vector<int> st; // Use a vector as a stack to handle collisions

        // Iterate through all asteroids
        for (int i = 0; i < n; ++i)
        {
            if (asteroids[i] > 0)
            {
                // Positive asteroid: moving to the right, push it onto the stack
                st.push_back(asteroids[i]);
            }
            else
            {
                // Negative asteroid: moving to the left
                // Process possible collisions with right-moving asteroids in the stack
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i]))
                {
                    // If the current negative asteroid is larger, destroy the top positive asteroid
                    st.pop_back();
                }

                // If the top positive asteroid and the current negative asteroid are equal
                if (!st.empty() && st.back() > 0 && st.back() == abs(asteroids[i]))
                {
                    st.pop_back(); // Destroy both asteroids
                }
                else if (st.empty() || st.back() < 0)
                {
                    // If no collision is possible (stack is empty or contains only left-moving asteroids),
                    // the current negative asteroid survives and is pushed onto the stack
                    st.push_back(asteroids[i]);
                }
            }
        }

        // Return the remaining asteroids after all collisions
        return st;
    }
};