#include <bits/stdc++.h>
using namespace std;
int solve(int *A, int n1, int B)
{
    int count = 0;
    for (int i = 0; i < n1; ++i)
    {
        int xor1 = 0;
        for (int j = i; j < n1; ++j)
        {
            xor1 ^= A[j];
            if (xor1 == B)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    return 0;
}