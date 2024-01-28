class Solution {
public:
    int trap(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> maxr(n), maxl(n);

        maxl[0] = heights[0] ;
        maxr[n-1] = heights[n-1] ;

        for(int i=1 ; i<n ; i++){
            maxl[i] = max(heights[i], maxl[i-1]);
        }

        for(int i=n-2 ; i>=0 ; i--){
            maxr[i] = max(heights[i], maxr[i+1]);
        }

        int sum = 0;
        for(int i=1; i<n-1; i++){
            sum += abs(min(maxl[i], maxr[i]) - heights[i]);
        }

        return sum;

    }
};