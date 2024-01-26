class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size() ;
        set<int> st;
        int max_cnt=1;

        for(auto it : nums){
            st.insert(it);
        }

        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int number = it;
                int count = 1;
                while(st.find(number+1) != st.end()){
                    number++;
                    count++;
                }
                max_cnt = max(max_cnt,count);
            }
        }

        return nums.size()==0 ? 0 : max_cnt;
    }
};