class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int hayLen = haystack.length();
        int needleLen = needle.length();

        if (needleLen == 0) {
            return 0;
        }

        for (int i = 0; i <= hayLen - needleLen; ++i) {
            int j = 0;

            while (j < needleLen && haystack[i + j] == needle[j]) {
                ++j;
            }

            if (j == needleLen) {
                return i;
            }
        }

        return -1;
    }
};