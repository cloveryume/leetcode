class Solution {
public:
    int divide(int dividend, int divisor) {
        return divide((long long )dividend, (long long)divisor);
    }

private:
    int divide(long long dividend, long long divisor) {
        bool sign = (dividend < 0)^(divisor < 0);
        if (dividend < 0) dividend = -dividend;
        if (divisor < 0) divisor = -divisor;

        if (divisor == 1) return dividend * (sign ? -1 : 1);

        long long low = 1, high = dividend, mid;
        while (low < high)
        {
            mid = (low + high) / 2;
            mid * divisor > dividend ? high = mid: low = mid + 1;
        }

        return --low * (sign ? -1 : 1);
    }
};
