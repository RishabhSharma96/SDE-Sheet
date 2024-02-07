class Solution 
{
    public:
 
    int solve(int arr[], int n, int maxPages){
        int students=1 ; int pagesHold = 0;
        
        for(int i=0 ; i<n ;i++){
            if(pagesHold + arr[i] <= maxPages){
                pagesHold += arr[i];
            }
            else{
                students++;
                pagesHold = arr[i];
            }
        }
        return students;
    }
 
    int findPages(int arr[], int n, int m) 
    {
        
        if(m > n){
            return -1;
        }
        
        int low = INT_MIN;
        int high = 0;
        
        for(int i=0; i<n; i++){
            low = max(low, arr[i]);
            high += arr[i];
        }
        
        while(low <= high){
            int midPages = high - (high-low)/2;
            int distributedStudentCount = solve(arr,n,midPages);
            
            if(distributedStudentCount > m){
                low = midPages+1;
            }
            else{
                high = midPages-1;
            }
        }
        
        return low;
    }
};