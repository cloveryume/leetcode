char alphabet[4][3] = {
    {'M', ' ', ' '},    // thousand
    {'C', 'D', 'M'},    // handred
    {'X', 'L', 'C'},    // ten
    {'I', 'V', 'X'}
};

class Solution {
public:
    string intToRoman(int num) {
        std::string s;
        for (int base = 1000, i = 0; base != 0; base /= 10, ++i) {
            int n = num / base;
            num %= base;
            if (n == 9) {
                s.push_back(alphabet[i][0]);
                s.push_back(alphabet[i][2]);
            }
            else if (n >= 5) {
                s.push_back(alphabet[i][1]);
                for (int j = 0; j < n - 5; ++j) s.push_back(alphabet[i][0]);
            }
            else if (n == 4) {
                s.push_back(alphabet[i][0]);
                s.push_back(alphabet[i][1]);
            }
            else {
                for (int j = 0; j < n; ++j) s.push_back(alphabet[i][0]);
            }
        }
        return s;
    }
};
