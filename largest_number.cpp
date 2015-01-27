#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Compare{
    bool operator()(int i, int j) {
        char buf1[40], buf2[40];
        snprintf(buf1, 40, "%d%d", i, j);
        snprintf(buf2, 40, "%d%d", j, i);
        return strcmp(buf1, buf2) > 0;
    }
}comp;

class Solution {
public:
    string largestNumber(vector<int> &num) {
        string ret;
        std::sort(num.begin(),num.end(),comp); 

        if (!num.empty() && num[0] == 0) return "0";

        for (int i = 0; i < num.size(); ++i) {
            char buf[40] = {'\0'};
            snprintf(buf, 40, "%d", num[i]);
            ret += buf;
        }
        return ret;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    vector<int> vec = {1, 2, 2, 1};
    cout << s.largestNumber(vec) << endl;

    return 0;
}
