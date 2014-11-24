class Solution {
public:
    string simplifyPath(string path) {
        string str,ret;
        stack<string> s;
        
        for (string::iterator it = path.begin(); it != path.end(); ++it) 
        {
            if (*it == '/')
            {
                handlePath(s, str);
                str.clear();
            }
            else 
            {
                str.push_back(*it);
            }
        }

        // last
        if (!str.empty()) handlePath(s, str);

        if (s.empty()) ret = "/";

        while (!s.empty())
        {
            ret = "/" + s.top() + ret;
            s.pop();
        }

        return ret;
    }

private:
    void handlePath(stack<string>& s, const string& str)
    {
        if (str == "..")
        {
            if (!s.empty()) s.pop(); 
        }
        else if (!str.empty() && str != ".")
        {
            s.push(str);
        }
    }
};
