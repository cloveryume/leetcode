class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int a, b;
        char op;
        for (int i = 0; i < tokens.size(); ++i) {
            const string& token = tokens[i];

            if (!getOperator(token, &op)) {
                s.push(atoi(token.c_str()));
                continue;
            }

            b = s.top(); s.pop();
            a = s.top(); s.pop();
            switch (op) {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            }
        }
        return s.top();
    }

private:
    bool getOperator(const string& token, char *op) {
        bool pred = token == "+" || token == "-" || 
            token == "*" || token == "/";
        if (pred) *op = token[0];
        return pred;
    }
};
