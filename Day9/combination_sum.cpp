class Solution {
public:

    void solve(vector<int>& candidates, int target, int index, vector<vector<int>> & ans,vector<int> & helper){

        if(target == 0){
            ans.push_back(helper);
            return;
        }

        if(index == candidates.size()){
            return ;
        }

        solve(candidates,target,index+1,ans,helper);
        helper.push_back(candidates[index]);
        if(candidates[index] <= target) {
            solve(candidates,target-candidates[index],index,ans,helper);
        }
        helper.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> helper;
        int n = candidates.size();
        solve(candidates,target,0,ans, helper);
        return ans;

    }
};