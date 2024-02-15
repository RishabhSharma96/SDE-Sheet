#include<bits/stdc++.h>

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size() ;
        int  i=0, j=0;
        vector<int> ans;
        deque<int> dq;

        while(j<n){

            while(dq.size()>0 && dq.front() < nums[j]){
                dq.pop_front();
            }
            dq.push_front(nums[j]);

            if(j-i+1 == k){
                if(dq.size() > 0){
                    ans.push_back(dq.back());
                }
            }
            else{
                while(j-i+1 > k){
                    if(dq.size()>0 && dq.back() == nums[i]){
                        dq.pop_back();
                    }
                    i++;
                }
                if(j-i+1 == k){
                    ans.push_back(dq.back());
                }
            }
            j++;
        }
        return ans;
    }
};