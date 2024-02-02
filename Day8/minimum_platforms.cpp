class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int platforms=0, maxPlatforms=0, arrival=0, departure=0;
        
        while(arrival < n){
            if(arr[arrival] <= dep[departure]){
                platforms++;
                arrival++;
            }
            else{
                platforms--;
                departure++;
            }
            maxPlatforms = max(maxPlatforms, platforms);
        }
    return maxPlatforms;
    }
};