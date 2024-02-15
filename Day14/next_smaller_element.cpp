class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        stack<int> s ;
        s.push(-1);
        vector<int> ans;
        
        for(int i=0 ; i<n ; i++){
            while(s.top() >= a[i]){
                s.pop();
            } 
            ans.push_back(s.top());
            s.push(a[i]);
        }
        
        return ans;
    }
};