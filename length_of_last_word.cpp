class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (NULL == s || strlen(s) == 0) return 0;

        int length = 0;

        char *p = (char *)s + strlen(s) - 1;

        //skip tailer space
        while(p >= s)
        {
            if (*p == ' ') 
                --p;
            else
                break;
        }
        
        while(p >= s)
        {
            if (*p == ' ')
            {
                break;
            }
            else
            {
                --p;
                ++length;
            }
        }

        return length;
    }
};
