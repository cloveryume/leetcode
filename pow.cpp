class Solution {
public:
    double pow(double x, int n) {
        if (0 == n)  return 0 == x ? 0 : 1;

        if (x == 1) return 1;

        if (x == -1) return n % 2 == 0 ? 1 : -1;

        double result = 1;
        bool negative  = n < 0;

        if (negative) n = -n;

        for (int i = 0; i < n; ++i)
        {
            result *= x;
            if (result == 0) break;
        }

        return negative ? 1 / result : result;
    }
};
