class Solution {
public:
    int climbStairs(int n) {
        return fib(n + 1);
    }

private:
    int fib(int n)
    {
        if (0 >= n) return 0;
        if (1 == n) return 1;

        int i = 0, j = 1;
        
        for (int k = 2; k <= n; ++k)
        {
            j = i + j;
            i = j - i;
        }

        return j;
    }
};
