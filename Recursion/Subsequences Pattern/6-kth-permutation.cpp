/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        // this is not a recursive solution
        int fact = 1;        // to calculate n-1 factorial
        vector<int> numbers; // to make number
        for (int i = 1; i < n; ++i)
        {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n); //[1,2,3,...n] is created now
        string ans = "";      // answer string
        k = k - 1;            // due to 0 based indexing
        while (true)
        {
            ans = ans + to_string(numbers[k / fact]);  // finds the starting number
            numbers.erase(numbers.begin() + k / fact); // erase that to avoid reuse
            if (numbers.size() == 0)                   // base condition
            {
                break; // if size becomes 0 we got our answer
            }
            k = k % fact;                 // update k value;
            fact = fact / numbers.size(); // we get the fact of the new size
        }
        return ans;
    }
};
