//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq ;
        // for -> {first_element, {array_index,element_index}}
        
        vector<int> ans;
        
        for(int i=0 ; i<K ; i++){
            pq.push({arr[i][0] , {i,0}});
        }
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop() ;
            
            int element = node.first;
            int arrIndex = node.second.first;
            int elementIndex = node.second.second;
            
            ans.push_back(element);
            if(elementIndex+1 < arr[arrIndex].size()){
                pq.push({arr[arrIndex][elementIndex+1],{arrIndex,elementIndex+1}});
            }
        }
        
        return ans;
    }
};