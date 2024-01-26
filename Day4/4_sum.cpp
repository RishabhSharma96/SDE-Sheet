class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size() ;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0 ; i<n ; i++){
            int a = nums[i] ;
            if(i>0 && a == nums[i-1]){
                continue;
            }
            for(int j=i+1 ; j<n ; j++){
                int b = nums[j];
                if(j>i+1 && b == nums[j-1]){
                    continue;
                }
                int left = j+1, right=n-1;
                while(left < right){
                    int c = nums[left], d=nums[right];
                    if((long)a+b+c+d == target){
                        ans.push_back({a,b,c,d});
                        left++;
                        right--;
                        while(left < right && nums[left] == c){
                            left++;
                        }
                        while(left < right && nums[right] == d){
                            right--;
                        }
                    }
                    else if((long)a+b+c+d < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};