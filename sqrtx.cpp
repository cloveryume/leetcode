class Solution {
public:
    int sqrt(int x)
    {
        long long i;
        x < 0 ? i = (long long)std::numeric_limits<int>::max() - x : i = x;
        return sqrt(i);
    }

private:
    int sqrt(long long x) {
        if (x == 0) return 0;

        long long low = 1, high = x + 1;
        while (low < high)
        {
            long long mid = (low + high) / 2;
            mid * mid > x ? high = mid : low = mid + 1;
        }

        return --low;
    }
};
