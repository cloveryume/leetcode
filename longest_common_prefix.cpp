class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string comm;
        if (strs.empty()) return comm;
        int i = 0;
        while (true) {
            for (int j = 0; j < strs.size(); ++j) {
               if (i >= strs[j].size()) return comm;  
               if (strs[j][i] != strs[0][i]) return comm;
            }
            comm.push_back(strs[0][i]);
            ++i;
        }
    }
};
