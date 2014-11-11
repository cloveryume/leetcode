class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (0 == n) return 0;

        int i = 0, j = 1;

        while (j < n) A[j] == A[i] ? ++j : A[++i] = A[j++];

        return i + 1;
    }
};
