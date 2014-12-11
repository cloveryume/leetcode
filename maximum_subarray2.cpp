class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxsum;
        maxSumEndWithLast(A, n, &maxsum);
        return maxsum;
    }

private:
    // 计算以A[n-1]为结尾的子向量的最大长度，并且与maxsum比较，更新maxsum
    int maxSumEndWithLast(int A[], int n, int *maxsum) {
        if (n == 1) { *maxsum = A[0]; return A[0]; }

        int sum = maxSumEndWithLast(A, n-1, maxsum);
        sum = sum < 0 ? A[n-1] : A[n-1] + sum;
        if (sum > *maxsum) *maxsum = sum;
        return sum;
    }
};
