// moores voting algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size() ;
        int currMajority = nums[0] ;
        int cnt=0 ;

        for(int i=0 ; i<n ; i++){
            
            if(cnt == 0){
                currMajority = nums[i] ;
            }

            if(nums[i] == currMajority){
                cnt++;
            }
            else{
                cnt-- ;
            }
        }

        cnt=0 ;
        for(int i=0 ; i<n ; i++){
            if(currMajority == nums[i]){
                cnt++;
            }
        }

        return cnt>n/2 ? currMajority : -1;
    }
};