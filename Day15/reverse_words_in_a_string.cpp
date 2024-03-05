class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size() ;
        string temp = "", ans = "";

        for(int i=0 ; i<n; i++){
            if(s[i] != ' '){
                temp.push_back(s[i]);
            }
            else{
                if(temp.size() > 0){
                    if(ans.size() == 0){
                        ans = temp;
                    }
                    else{
                        ans = temp + " " + ans;
                    }
                    temp = "";
                }
            }
        }

        if(temp.size()>0 && ans.size()>0){
            ans = temp + " " + ans;
        }
        else if(ans.size() == 0){
            return temp;
        }

        return ans ;
    }
};