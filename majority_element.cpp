class Solution {
public:
    int majorityElement(vector<int> &num) {
        int i = 0, j = 1;
        while (j < num.size()) {
            if (num[i] == num[j]) {
                ++j;
            }
            else {
                swap(num[i+1], num[j]);
                i += 2;
                j = j > i ? j : i + 1;
            }
        }
        return num[i];
    }
};
