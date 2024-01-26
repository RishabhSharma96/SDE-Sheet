class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int maxLen=0, sum=0;
        unordered_map<int,int> hashMap;
        hashMap[0]=0;
        
        for(int i=0; i<N; i++){
            sum+=A[i];

            int diff=sum-K;
            
            if(hashMap.find(diff)!=hashMap.end()){
                maxLen=max(i+1-hashMap[diff], maxLen);
            }
            
            if(hashMap.find(sum)==hashMap.end()){
                hashMap[sum]=i+1;
            }
        }
        
        return maxLen;
    } 

};