class Solution{
public:
    int subsetXOR(vector<int> arr, int N, int K) {
        
        int xr = 0;
        unordered_map<int,int>mpp;
        mpp[xr]++;
        int count=0;
        
        for(int i = 0 ; i<N; i++){
            xr = xr^ arr[i];
        
            int x= xr ^ K;
            count = count + mpp[x];
        
            mpp[xr] += mpp[x]+1;
        
        }
        
        return count ; 
    }
};