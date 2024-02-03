class Solution {
public:
    void solve(vector<int>& arr, int target, int index, vector<vector<int>> & ans, 
    vector<int> & helper){

        if(target == 0){
            ans.push_back(helper);
            return;
        }

        if(index == arr.size()){
            return ;
        }

        for(int i=index; i<arr.size() ; i++){
            if(i>index && arr[i] == arr[i-1]){
                continue;
            }

            if(target >= arr[i]){
                helper.push_back(arr[i]);
                solve(arr, target-arr[i], i+1, ans, helper);
                helper.pop_back();
            }
            else{
                break;
            }

        }  
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin() , candidates.end()); 
        
        vector<vector<int>> ans;
        vector<int> helper;
        solve(candidates,target,0,ans, helper);
        return ans;

    }
};