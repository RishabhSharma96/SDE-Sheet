class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size() , hillAtIndex = -1;

        for(int i=n-1; i>0 ; i--){
            if(nums[i] > nums[i-1]){
                hillAtIndex = i-1;
                break ;
            }
        }

        if(hillAtIndex == -1){
            sort(nums.begin(), nums.end());
            return ;
        }

        for(int i=n-1 ; i>hillAtIndex ; i--){
            if(nums[i] > nums[hillAtIndex]){
                swap(nums[i] , nums[hillAtIndex]);
                break ;
            }
        }

        sort(nums.begin()+hillAtIndex+1, nums.end());

    }
};