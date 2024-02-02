class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool cmp(pair<int,int> & a, pair<int,int> & b){
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meetTime; // for -> {start_time,end_time}
        for(int i=0; i<n ; i++){
            meetTime.push_back({start[i], end[i]});
        }
        
        sort(meetTime.begin(), meetTime.end(), cmp);
    
        
        int cnt=1;
        pair<int,int> timee =  meetTime[0];
        for(int i=1; i<n ; i++){
            if(timee.second < meetTime[i].first){
                timee = meetTime[i];
                cnt++;
            }
        }
        
        return cnt;
    }
};