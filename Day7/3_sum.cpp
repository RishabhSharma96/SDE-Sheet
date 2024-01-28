class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;

        for(int i=0 ; i<n ; i++){
            int a = nums[i] ;
            int j=i+1, k=n-1;

            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            while(j<k){
                int b = nums[j] ;
                int c = nums[k] ;
                int sum = a+b+c;
                if(sum == 0){
                    ans.push_back({a,b,c});
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k] == nums[k+1]){
                        k--;
                    }
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        return ans;

    }
};