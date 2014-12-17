class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        bool *dp = new bool[s.size() + 1];
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string word(s, j, i - j);
                if (dp[j] && dict.find(word) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
