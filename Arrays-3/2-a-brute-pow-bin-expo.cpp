class Solution
{
public:
    double myPow(double x, int n)
    {
        // brute force approach
        // will give tle
        // check for -integer n also
        long long nn = n;
        if (nn < 0)
            nn = -1 * n;
        double ans = 1;
        for (long long i = 0; i < nn; ++i)
        {
            ans *= x;
        }
        if (n < 0)
            ans = 1 / ans;
        return ans;
    }
};