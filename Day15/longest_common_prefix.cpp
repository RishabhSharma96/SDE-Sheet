class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size() ;
        string ans = "";

        for(int i=0 ; i<strs[0].size(); i++){
            for(int j=1 ; j<strs.size() ; j++){
                if(strs[j].size() == i || strs[j][i] != strs[0][i]){
                    return ans;
                }
            }
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};