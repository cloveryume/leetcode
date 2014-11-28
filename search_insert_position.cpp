class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (0 == n) return 0;

        int idx = binary_search(A, 0, n, target);

        if (idx >= 0 && idx < n && A[idx] == target) return idx;
        
        return ++idx;
    }

private:
    int binary_search(int A[], int low, int high, int target)
    {
        while (low < high)
        {
            int mid = (low + high) / 2;
            A[mid] > target ? high = mid : low = mid + 1;
        }

        return --low;
    }
};
