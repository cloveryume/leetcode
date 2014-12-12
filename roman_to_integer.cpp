class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            switch (c) {
            case 'M':
            case 'D':
                ret += (c == 'M' ? 1000 : 500);
                while (i >= 1 && s[i-1] == 'C') {--i; ret -= 100; }
                break;
            case 'C':
            case 'L':
                ret += (c == 'C' ? 100 : 50);
                while (i >= 1 && s[i-1] == 'X') {--i; ret -= 10; }
                break;
            case 'X':
            case 'V':
                ret += (c == 'X' ? 10 : 5);
                while (i >= 1 && s[i-1] == 'I') {--i; ret -= 1; }
                break;
            case 'I':
                ret += 1;
            }
        }
        return ret;
    }
};
