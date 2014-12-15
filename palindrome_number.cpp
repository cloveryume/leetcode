class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x != 0 && x % 10 == 0) return false;

        int reverse = 0;
        int mod = 0;
        while (reverse < x) {
            mod = x % 10;
            x /= 10;
            if (reverse * 10 + mod > x) return x == reverse;  // 位数为单的情况
            reverse = reverse * 10 + mod; 
        }
        return reverse == x;
    }
};
