class Solution {
public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {

        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        
        set<pair<int,int>> s;
        priority_queue<pair<int,pair<int,int>>> pq;
        
        pq.push({a[0]+b[0],{0,0}});
        
        s.insert({0,0});
        vector<int> ans;
        
        while(!pq.empty() && k--){
            
            int sum=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            
            ans.push_back(sum);
            
            if(i<n-1 && s.find({i+1,j})==s.end()){
                pq.push({a[i+1]+b[j],{i+1,j}});
                s.insert({i+1,j});
            }
            if(j<n-1 && s.find({i,j+1})==s.end()){
                pq.push({a[i]+b[j+1],{i,j+1}});
                s.insert({i,j+1});
            }
        
        }
        return ans;
        
    }
};