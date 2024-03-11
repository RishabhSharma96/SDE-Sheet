class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> ans;
        int i=0, j=0;
        unordered_map<int,int> mp;
        
        while(j<n){
            mp[A[j]]++;
            
            if(j-i+1 == k){
                ans.push_back(mp.size());
            }
            else if(j-i+1 > k){
                while(j-i+1 > k){
                    mp[A[i]]--;
                    if(mp[A[i]] == 0){
                        mp.erase(A[i]);
                    }
                    i++;
                }
                if(j-i+1 == k){
                    ans.push_back(mp.size());
                }
            }
            j++;
        }
        return ans;
    }
};