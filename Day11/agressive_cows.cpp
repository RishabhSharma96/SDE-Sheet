class Solution {
public:

    int helper(vector<int> stalls, int n, int maxDist){
        int cows = 1, placedAt = stalls[0];
        
        for(int i=1; i<n ; i++){
            if(abs(stalls[i] - placedAt) < maxDist){
                continue;
            }
            else{
                cows++;
                placedAt = stalls[i] ;
            }
        }
        return cows;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin() , stalls.end());
        int low=0, high = (stalls[n-1] - stalls[0]);
        int ans = -1;
        
        while(low <= high){
            
            int threshhold = low + (high - low)/2;
            int cowsPlaced = helper(stalls, n , threshhold);
            
            if(cowsPlaced < k){
                high = threshhold - 1;
            }
            else{
                ans = threshhold;
                low = threshhold + 1;
            }
        }
        return ans;
    }
};