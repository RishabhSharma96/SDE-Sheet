class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> merged ;
        sort(intervals.begin(), intervals.end());
        
        for(auto & it : intervals){
            if((merged.size() == 0) || (merged.size() > 0 && it[0] > merged.back()[1])){
                merged.push_back(it);
            }
            else{
                merged.back()[1] = max(merged.back()[1] , it[1]);
                merged.back()[0] = min(merged.back()[0] , it[0]);
            }
        }

        return merged ;
        
    }
};