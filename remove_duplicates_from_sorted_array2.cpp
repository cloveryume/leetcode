class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (0 == n) return 0;

        int i = 0, j = 1;
        int count = 0;
        while (j < n)
        {
            if (A[i] == A[j])
            {
                ++count < 2 ? A[++i] = A[j++] : ++j;
            }
            else 
            {
                A[++i] = A[j++];
                count = 0;
            }
        }

        return i + 1;
    }
};
