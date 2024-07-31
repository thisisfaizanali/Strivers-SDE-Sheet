#include <bits/stdc++.h>
using namespace std;
int solve(int *A, int n1, int B)
{
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int count = 0;
    for (int i = 0; i < n1; ++i)
    {
        xr ^= A[i];
        int x = xr ^ B;
        count = count + mpp[xr];
        mpp[xr]++;
    }
}
int main()
{
    return 0;
}