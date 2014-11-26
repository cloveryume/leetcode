class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (NULL == haystack || NULL == needle) return -1;

        if (strlen(needle) == 0) return 0;

        bool match = false;
        int j, k;

        for (int i = 0; i < strlen(haystack); ++i)
        {
            j = i;
            match = true;
            k = 0;

            while (j < strlen(haystack) && k < strlen(needle))
            {
                if (haystack[j++] != needle[k++])
                {
                    match = false;
                    break;
                }
            }

            match = match && k == strlen(needle);

            if (match) return i;

            if (j == strlen(haystack)) return -1;
        }

        return -1;
    }
};
