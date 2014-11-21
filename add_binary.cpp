class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        int carry = 0;
        int sum;

        while(!a.empty() || !b.empty() || carry)
        {
            sum = (a.empty() ? 0 : a[a.size() - 1] - '0') + 
                (b.empty() ? 0 : b[b.size() - 1] - '0') + carry;

            if (!a.empty()) a.erase(a.end() - 1);
            if (!b.empty()) b.erase(b.end() - 1);

            carry = sum / 2;
            c.insert(c.begin(), sum % 2 + '0');
        }

        return c;
    }
};
