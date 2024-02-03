class Solution {
public:
    string getPermutation(int n, int k) {
        
        int factorial = 1 ;
        vector<int> nums; 

        for(int i=1; i<n; i++){
            nums.push_back(i);
            factorial *= i ;
        }
        nums.push_back(n);

        k-- ;
        string ans = "";

        while(nums.size() != 0){
            ans = ans + (to_string(nums[k/factorial]));
            nums.erase(nums.begin() + k/factorial);
            if(nums.size() == 0){
                break;
            }
            k = k%factorial;
            factorial = factorial/nums.size();
        }

        return ans;

    }
};