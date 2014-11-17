#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.empty() || num2.empty()) return "";

        int *result = new int[num1.size() + num2.size()]();
        int length;
        int a, b, c, k;
        for (int i = 0; i < num1.length(); ++i)
        {
            for (int j = 0; j < num2.length(); ++j)
            {
                a = num1[num1.length() - 1 - i] - '0';
                b = num2[num2.length() - 1 - j] - '0';
                c = a * b;

                result[i+j] += c;
                k = i + j;
                length = k + 1;

                while(result[k] > 9)
                {
                    result[k+1] += result[k]/10;
                    result[k] %= 10;
                    ++length;
                    ++k;
                }
            }
        }

        // 去除前置的0
        for (int i = length - 1; i > 0; --i)
        {
            if (result[i] == 0)
                --length;
            else
                break;
        }

        std::string ret(length, '0');
        for (int i = 0; i < length; ++i)
        {
            ret[i] = result[length - 1 - i] + '0';
        }
        delete []result;

        return ret;
    }
};
