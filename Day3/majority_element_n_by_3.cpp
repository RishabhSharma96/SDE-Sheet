// extended moores voting algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size() ;
        vector<int> ans;

        if(nums.size() == 1){
            return nums;
        }

        int cnt1=0, cnt2=0, element1=nums[0], element2=nums[1] ;

        for(int i=0 ; i<n ; i++){
            if(cnt1==0 && nums[i] != element2){
                element1 = nums[i] ;
            }
            if(cnt2==0 && nums[i] != element1){
                element2 = nums[i] ;
            }

            if(nums[i] == element1){
                cnt1++;
            }
            else if(nums[i] == element2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        } 

        cnt1=0 , cnt2=0 ;

        for(int i=0 ; i<n ; i++){
            if(element1 == nums[i]){
                cnt1++;
            }
            else if(element2 == nums[i]){
                cnt2++;
            }
        }

        int minTimes = n/3;

        if(cnt1 > minTimes){
            ans.push_back(element1);
        }
        if(cnt2 > minTimes){
            ans.push_back(element2);
        }

        return ans;
        
    }
};