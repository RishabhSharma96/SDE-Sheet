class MedianFinder {
private:
    priority_queue<int> smallHeap; 
    priority_queue<int, std::vector<int>, std::greater<int>> largeHeap; 

public:
    MedianFinder(){}

    void addNum(int num) {
        if(smallHeap.empty() || (smallHeap.top()>num)) {
            smallHeap.push(num); 
        }
        else{
            largeHeap.push(num); 
        } 
        
        if(smallHeap.size() > largeHeap.size()+1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        else if(smallHeap.size()+1 < largeHeap.size()){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }

    double findMedian() {
        if(smallHeap.size() == largeHeap.size()) {
            return smallHeap.empty() ? 0 : ( (smallHeap.top()+largeHeap.top())/2.0);
        }
        else{
            return (smallHeap.size() > largeHeap.size()) ? smallHeap.top() : largeHeap.top(); 
        }
    }
};