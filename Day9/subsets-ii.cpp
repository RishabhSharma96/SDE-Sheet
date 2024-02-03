class Solution {
public:
    
    void solve(vector<int> & arr, vector<vector<int>>& ans,  vector<int>& helper, int index){

        ans.push_back(helper);

        for(int i=index ; i<arr.size() ; i++){

            if((i>index)&&(arr[i] == arr[i-1])){
                continue ;
            }

            helper.push_back(arr[i]);
            solve(arr,ans,helper,i+1) ;
            helper.pop_back() ;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> & nums){
        vector<vector<int>> ans;
        vector<int> helper;
        solve(nums, ans, helper, 0);
        return ans;
    }
};