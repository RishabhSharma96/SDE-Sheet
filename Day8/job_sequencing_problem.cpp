/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    static int cmp(struct Job & j1, struct Job & j2){
        return j1.profit > j2.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n , cmp);
        
        int maxDeadline = arr[0].dead;
        for(int i=0; i<n ; i++){
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        vector<int> schedule(maxDeadline+1, -1);
        int profit=0, count=0;
        
        for(int i=0; i<n ; i++){
            if(schedule[arr[i].dead] == -1){
                schedule[arr[i].dead] = arr[i].id;
                profit += arr[i].profit;
                count++;
            }
            else{
                int currId = arr[i].dead;
                while(currId > 0 && schedule[currId] != -1){
                    currId--;
                }
                if(currId > 0){
                    schedule[currId] = arr[i].id;
                    profit += arr[i].profit;
                    count++;
                }
            }
        }
        
        return {count, profit};
    } 
};
