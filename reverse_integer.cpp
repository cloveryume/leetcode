class Solution {
public:
    int reverse(int x) {
        bool sign = x < 0;

        if (sign) x = -x;

        long long ret = 0;
        while (x != 0) {
            ret = ret * 10 + x % 10;
            x = x / 10;
        }

        if (sign) ret = -ret;

        if (ret > std::numeric_limits<int>::max() ||
                ret < std::numeric_limits<int>::min())
            return 0;

        return ret;
    }
};
