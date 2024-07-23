class Solution
{
public:
    double myPow(double x, int n)
    {
        // n is always positive or negative?
        // done in O log(n)
        // lets solve using bitwise operators
        double res = 1;
        long long nn = n;
        if (nn < 0)
        {
            // error prone if nn = -1 * n;
            nn = -nn;
        }
        while (nn > 0)
        {
            if (nn & 1)
                res = res * x;
            // dont need to decrease nn by 1, because of bitwise alignment
            x = x * x;
            nn >>= 1;
        }
        if (n < 0)
            res = (double)(1.0) / (double)(res);
        return res;
    }
};