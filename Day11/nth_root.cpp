class Solution{
	public:
	int NthRoot(int n, int m){
        
        int start=1, end=m;
        
        while(start <= end){
            int mid = (end - ((end-start)/2));
            
            if(pow(mid,n) == m){
                return mid ;
            }
            else if(pow(mid,n) < m){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        
        return -1;
        
	}  
};