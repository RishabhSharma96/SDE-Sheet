class Solution{
    public:
    
    int solve(int a[], int b[], int len1, int len2, int k) {
        
        int n1 = len1, n2 = len2;

        int n = n1 + n2; 
        int left = k; 

        int low=max(0, k-n2), high=min(k, n1);
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1){
                r1 = a[mid1];
            } 
            if (mid2 < n2){
                r2 = b[mid2];
            } 
            if (mid1 - 1 >= 0){
                l1 = a[mid1 - 1];
            } 
            if (mid2 - 1 >= 0){
                l2 = b[mid2 - 1];
            } 

            if (l1 <= r2 && l2 <= r1) {
                return max(l1,l2);
            }
            else if (l1 > r2){
                high = mid1 - 1;
            }
            else{
                low = mid1 + 1;
            } 
                
        }
        return 0; 
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n < m){
            return solve(arr1,arr2,n,m,k);
        }
        else{
            return solve(arr2,arr1,m,n,k);
        }
    }
};