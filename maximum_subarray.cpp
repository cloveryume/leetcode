class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) return 0;

        int *dp = new int[n];  // 以A[i]结尾的最大长度
        dp[0] = A[0];
        int maxsum = dp[0];

        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i-1] < 0 ? A[i] : dp[i-1] + A[i];
            if (dp[i] > maxsum) maxsum = dp[i];
        }

        delete []dp;
        return maxsum;
    }
};
