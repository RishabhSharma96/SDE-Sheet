class Solution{
    public:
    
    void nextSmallerElement(int arr[], vector<int>& nse, int n){

        stack<pair<int,int>> s;
        for(int i=n-1; i>=0 ; i--){
            while(!s.empty() && s.top().first >= arr[i]){
                s.pop();
            }

            if(s.empty()){
                nse.push_back(n);
            }
            else{
                nse.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }

        reverse(nse.begin(), nse.end());
    }

    void previousSmallerElement(int arr[], vector<int>& pse, int n){
        stack<pair<int,int>> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && s.top().first >= arr[i]){
                s.pop();
            }

            if(s.empty()){
                pse.push_back(-1);
            }
            else{
                pse.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
    }
    
    vector <int> maxOfMin(int arr[], int n){
        
        vector<int> nse,pse ;
        nextSmallerElement(arr, nse, n);
        previousSmallerElement(arr, pse, n);
        
        vector<int> ans(n+1, 0) ;
        
        for(int i=0 ; i<n ; i++){
            int windowSize = nse[i] - pse[i] - 1;
            ans[windowSize] = max(ans[windowSize], arr[i]);
        }
        
        for(int i=n-1 ; i>=0 ; i--){
            ans[i] = max(ans[i+1], ans[i]);
        }
        
        ans.erase(ans.begin());
        
        return ans;
    }
    
};