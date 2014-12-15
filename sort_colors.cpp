class Solution {
public:
    void sortColors(int A[], int n) {
        if (n < 2) return;

        int i = 0, j = n - 1;   /* 0 0 0 i ...... j 2 2 2 2 */
        for (int k = 0; k <= j; ) {
            switch(A[k]) {
            case 0:
                if (i == k) { k++; continue; }
                swap(A[i++], A[k]);
                break;
            case 1:
                ++k;
                break;
            case 2:
                swap(A[k], A[j--]);
                break;
            }
        }
    }
private:
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
