class Solution
{
public:

    void solve(vector<int> arr, vector<int> & ans, int sum, int index){
        if(index == arr.size()){
            ans.push_back(sum);
            return ;
        }
        
        solve(arr, ans, sum+arr[index], index+1);
        solve(arr, ans, sum, index+1);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(arr, ans, 0, 0);
        return ans;
    }
};