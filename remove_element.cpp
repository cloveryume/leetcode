class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (0 == n) return 0;

        int i = -1, j = 0;

        while (j < n) { A[j] == elem ? ++j : A[++i]= A[j++]; }

        return i+1;
    }
};
