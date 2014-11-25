class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;

        int carray = 1, sum;
        int i = digits.size() - 1;

        while (i >= 0 || carray)
        {
            i >=0 ? sum = carray + digits[i] : sum = carray;
            
            result.push_back(sum % 10);
            carray = sum / 10;
            --i;
        }

        std::reverse(result.begin(), result.end());
        
        return result;
    }
};
