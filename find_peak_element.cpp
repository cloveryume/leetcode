class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int low = 0, high = num.size();
        int mid;
        while (low < high) {
            mid = (low + high) / 2;

            if (compare(num, mid, mid - 1) > 0 &&
                    compare(num, mid, mid + 1) > 0)
                return mid;

            if (compare(num, mid, mid - 1) < 0) // 左边有逆序
                high = mid;
            else
                low = mid + 1;
        }
        return -1;
    }

private:
    int compare(const vector<int>& num, int idx1, int idx2)
    {
        if (idx1 < 0 || idx1 >= num.size()) return -1;
        if (idx2 < 0 || idx2 >= num.size()) return 1;
        return num[idx1] - num[idx2];
    }
};
