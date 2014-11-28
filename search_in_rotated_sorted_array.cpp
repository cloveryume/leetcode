class Solution {
public:
    int search(int A[], int n, int target) {
        int low = 0, high = n;
        while (low < high) {
            int mid = (low + high) / 2;

            if (A[mid] == target) return mid;

            if (A[mid] > target) {
                if (A[mid] > A[high - 1]) // mid 位于前半部分
                    A[low] > target ? low = mid + 1 : high = mid;
                else
                    high = mid;
            }
            else {
                if (A[mid] > A[high - 1]) // mid 位于前半部分
                {
                    low = mid + 1;
                }
                else
                {
                    A[high-1] < target ? high = mid : low = mid + 1;
                }
            }
        }

        return -1;
    }
};
