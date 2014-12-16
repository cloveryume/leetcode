class Solution {
public:
    int compareVersion(string version1, string version2) {
        version v1(version1);
        version v2(version2);
        return compare(v1, v2);
    }

private:
    struct version {
        vector<int> revisions;

        version(const std::string& str) {
            parseFromString(str);
        }

        void parseFromString(const std::string& str) {
            int pos = 0;
            int dot = 0;
            while ((dot = str.find('.', pos)) != string::npos) {
                std::string rev(str, pos, dot);
                revisions.push_back(atoi(rev.c_str()));
                pos = dot + 1;
            }
            std::string rev(str, pos);
            revisions.push_back(atoi(rev.c_str()));
        }
    };

    int compare(const version& lhs, const version& rhs) {
        for (int i = 0; i < lhs.revisions.size() || i < rhs.revisions.size(); ++i) {
            int a =  i >= lhs.revisions.size() ? 0 : lhs.revisions[i];
            int b =  i >= rhs.revisions.size() ? 0 : rhs.revisions[i];
            if (a > b)
                return 1;
            else if (a < b)
                return -1;
        }
        return 0;
    }
};
