class Solution{
	public:
	
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
        sort(coins.begin(), coins.end(), greater<int>());
        
        int numCoins=0 ;
        for(int i=0 ; i<M; i++){
            int numParticularCoins = V/coins[i] ;
            numCoins += numParticularCoins;
            V -= numParticularCoins*coins[i];
        }
        
        return numCoins;
	} 
};