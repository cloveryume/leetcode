class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;

        int low = lower_bound(A, 0, n, target);
        int high = upper_bound(A, 0, n, target);

        if (low <= high)
        {
            result.push_back(low);
            result.push_back(high);
        }
        else
        {
            result.push_back(-1);
            result.push_back(-1);
        }

        return result;
    }

private:
    int upper_bound(int A[], int low, int high, int target)
    {
        int mid;
        while (low < high)
        {
            mid = (low + high) / 2;
            A[mid] > target ? (high = mid) : (low = mid + 1);
        }

        return --low;
    }

    int lower_bound(int A[], int low, int high, int target)
    {
        int mid;
        while (low < high)
        {
            mid = (low + high) / 2;
            A[mid] < target ? (low = mid + 1) : (high = mid);
        }

        return low;
    }
};
