class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    
    static bool cmp(pair<int,int> & a, pair<int,int> & b){
        return a.second < b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>> workpair; // for -> {start_time,end_time}
        for(int i=0; i<n ; i++){
            workpair.push_back({start[i], end[i]});
        }
        
        sort(workpair.begin(), workpair.end(), cmp);
        
        int cnt=1;
        pair<int,int> currWork =  workpair[0];
        for(int i=1; i<n ; i++){
            if(currWork.second < workpair[i].first){
                currWork = workpair[i];
                cnt++;
            }
        }
        
        return cnt;
    }
};