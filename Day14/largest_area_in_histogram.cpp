class Solution {
public:

    void nextSmallerElement(vector<int>& heights, vector<int>& nse){

        stack<pair<int,int>> s;
        for(int i=heights.size()-1; i>=0 ; i--){
            while(!s.empty() && s.top().first >= heights[i]){
                s.pop();
            }

            if(s.empty()){
                nse.push_back(heights.size());
            }
            else{
                nse.push_back(s.top().second);
            }
            s.push({heights[i], i});
        }

        reverse(nse.begin(), nse.end());
    }

    void previousSmallerElement(vector<int>& heights, vector<int>& pse){
        stack<pair<int,int>> s;
        for(int i=0; i<heights.size(); i++){
            while(!s.empty() && s.top().first >= heights[i]){
                s.pop();
            }

            if(s.empty()){
                pse.push_back(-1);
            }
            else{
                pse.push_back(s.top().second);
            }
            s.push({heights[i], i});
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> nse,pse ;
        nextSmallerElement(heights, nse);
        previousSmallerElement(heights, pse);

        long long maxArea = 0;

        for(int i=0 ; i<heights.size() ; i++){
            int leftTaken = pse[i]+1;
            int rightTaken = nse[i]-1;
            long long currArea = (heights[i]*(rightTaken-leftTaken+1));
            maxArea = max(maxArea,currArea);
        }

        return maxArea;

    }
};