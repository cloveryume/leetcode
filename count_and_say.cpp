class Solution {
public:
    string countAndSay(int n) {
        string result;
        if (n < 1)  return result;

        result = "1";

        for (int i = 0; i < n - 1; ++i)
            result = countAndSayOnce(result);

        return result;
    }

private:
    string countAndSayOnce(const string& str) {
        string ret;
        int count = 0;
        char ch = str[0];

        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == ch) { ++count; continue; }

            ret += intToString(count);
            ret.push_back(ch);

            ch = str[i];
            count = 1;
        }

        ret += intToString(count);
        ret.push_back(ch);

        return ret;
    }

    string intToString(int i) {
        string ret;
        do {
            ret.insert(ret.begin(), i % 10 + '0');
            i = i / 10;
        } while(i != 0);

        return ret;
    }
};
