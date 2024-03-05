class Solution {
public:
    string countAndSay(int n) {

        if(n == 1){
            return "1" ;
        }

        string prevNumString = countAndSay(n-1);

        string temp="";
        int i=0 ;

        while(i<prevNumString.size()){
            char ch = prevNumString[i];
            int cnt=0;
            while(prevNumString[i]==ch && i<prevNumString.size()) {
                cnt++;
                i++;
            }
            temp.push_back(cnt+'0');
            temp.push_back(prevNumString[i-1]);
        }

        return temp ;
    }
};