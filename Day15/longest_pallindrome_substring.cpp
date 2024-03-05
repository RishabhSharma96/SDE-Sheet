class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size(), start = 0, end = 0, len = 0;

        // odd length
        for (int i = 0; i < n; i++) {
            int ps = i, pe = i;
            while (ps >= 0 && pe < n) {
                if (s[ps] == s[pe]) {
                    ps--;
                    pe++;
                } 
                else {
                    break;
                }
            }
            if (pe - ps + 1 > len) {
                len = pe - ps + 1;
                start = ps+1;
                end = pe-1;
            }
        }

        // even length
        for (int i = 0; i < n; i++) {
            int ps = i, pe = i + 1;
            while (ps >= 0 && pe < n) {
                if (s[ps] == s[pe]) {
                    ps--;
                    pe++;
                } 
                else {
                    break;
                }
            }
            if (pe - ps + 1 > len) {
                len = pe - ps + 1;
                start = ps+1;
                end = pe-1;
            }
        }

        return s.substr(start, end-start+1);
    }
};