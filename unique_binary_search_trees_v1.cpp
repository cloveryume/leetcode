class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) return 1;

        int ret = 0;
        for (int i = 1; i <=n ; ++i)
            ret += numTrees(i - 1) * numTrees(n - i);

       return ret;
    }
};
