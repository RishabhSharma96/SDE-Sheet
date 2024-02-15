class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        int currCeleb = 0 ;
        for(int i=1; i<n ; i++){
            if(arr[currCeleb][i] == 1){
                currCeleb = i;
            }
        }
        
        for(int i=0 ; i<n ; i++){
            if(i == currCeleb){
                continue;
            }
            else if(arr[currCeleb][i] == 1 || arr[i][currCeleb] == 0){
                return -1;
            }
        }
        
        return currCeleb;
    }
};