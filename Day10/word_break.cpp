class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<int> isFound(n+1, false);

        isFound[n] = true;

        for(int i=n-1; i>=0 ; i--){
            for(auto it : wordDict){
                if((i+it.size() <= n) && (s.substr(i,it.size()) == it)){
                    isFound[i] = isFound[i+it.size()];
                }
                if(isFound[i] == true){
                    break;
                }
            }
        }

        return isFound[0];

    }
};