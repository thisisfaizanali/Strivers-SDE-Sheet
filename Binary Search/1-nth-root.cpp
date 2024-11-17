/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int NthRoot(int n, int m)
    {
        // we have  a range and max  or min or value
        //-> that means this is bs on answers

        // we need to calculate m^(1/n) :
        // let x = m^(1/n) :
        // => x ^ n = m;
        //=> this means x is the answer
        if (m == 1)
            return 1; // special case
        int low = 1, high = m;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // we need to caclulate the value of mid ^ n
            //  mid is the potential answer
            long long value = power(mid, n, m);
            if (value == m)
            {
                return mid;
            }
            else if (value < m)
            {
                low = mid + 1; // go towards bigger side
            }
            else
            {
                high = mid - 1; // go towards smaller side
            }
        }
        return -1;
    }

private:
    long long power(int a, int b, int m)
    {
        long long res = 1;
        for (int i = 1; i <= b; ++i)
        {
            res = res * a;
            if (res > m)
            {
                break; // avoid overflow as ans will never cross m
            }
        }
        return res;
    }
};