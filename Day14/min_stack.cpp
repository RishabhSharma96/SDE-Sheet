class MinStack {
public:

    stack<long long> s;
    long long minElement;

    MinStack(){
        minElement = 0 ;
    }

    void push(int val){
        if(s.empty()){
            s.push(val);
            minElement = val;
        }
        else{
            if(val < minElement){
                s.push((long long)2*val - minElement);
                minElement = val;
            }
            else{
                s.push(val);
            }
        }
    }

    void pop(){
        if(s.top() >= minElement){
            s.pop();
        }
        else{
            minElement = (long long)2*minElement - s.top() ;
            s.pop(); 
        }
    }

    int top() {
        if(s.top() >= minElement){
            return s.top();
        }
        else{
            return minElement;
        }
    }

    int getMin(){
        return minElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */