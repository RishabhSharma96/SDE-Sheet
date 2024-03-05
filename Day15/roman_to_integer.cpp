class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> values;
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;

        int n = s.size() ;
        long long num = values[s[0]];

        for(int i=1 ; i<n ; i++){
            if(values[s[i]] <= values[s[i-1]]){
                num += values[s[i]];
            }
            else{
                num += (values[s[i]] - 2*values[s[i-1]]);
            }
        }

        return num;

    }
};