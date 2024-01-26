class Solution {
public:

    int lengthOfLongestSubstring (string str){
    int n = str.size();
    int i = 0, j = 0;

    int maxLen = 0;

    unordered_map<char, int> freq;

    while(j < n) {

        freq[str[j]]++;

        if(freq.size() == j-i+1) {
            maxLen = max(maxLen, j-i+1);
            j++;
        }

        else if(freq.size() < j-i+1) {
            while(freq.size() < j-i+1) {
                freq[str[i]]--;
                if(freq[str[i]] == 0) {
                    freq.erase(str[i]);
                }
                i++;
            }
            if(freq.size() == j-i+1){
                maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
    }
    return maxLen;
}

};