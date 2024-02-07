class Solution{   
public:

    int findSmallerElementsCount(vector<vector<int>> &matrix, int n, int m, int num){
        
        int cnt = 0;
        
        for(int i=0 ; i<n ; i++){
            cnt += (upper_bound(matrix[i].begin(), matrix[i].end() , num) - matrix[i].begin());
        }
        return cnt;
    }

    int median(vector<vector<int>> &matrix, int n, int m){
        int low = INT_MAX, high = INT_MIN;
        
        for(int i=0 ; i<n ;i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m-1]);
        }
        
        while(low <= high){
            int mid = high - (high-low)/2;
            int smallerElementsCount = findSmallerElementsCount(matrix, n, m, mid);

            if(smallerElementsCount <= (n*m)/2){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
    
};