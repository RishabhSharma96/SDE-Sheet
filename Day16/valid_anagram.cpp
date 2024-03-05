class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        
        vector<int> freq(26,0);

        for(int i=0 ; i<s.size() ; i++){
            int index = s[i] - 'a';
            freq[index]++ ;
        }

        for(int i=0 ; i<t.size() ; i++){
            int index = t[i] - 'a';
            if(freq[index] == 0){
                return false;
            }
            freq[index]--;
        }

        return true;

    }
};