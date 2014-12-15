class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;

        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (!isalnum(s[i])) {++i; continue; }
            if (!isalnum(s[j])) {--j; continue; }

            if (equal(s[i], s[j])) {
                ++i;
                --j; 
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }

private:
    inline bool equal(char c1, char c2) {
        return c1 == c2 || abs(c1 - c2) == (97 - 65);
    }
};
