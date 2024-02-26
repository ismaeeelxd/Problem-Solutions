class MinStack {
    stack<int>stac;
    stack<int>mins;
public:
    MinStack() {
    }

    void push(int val) {
        if(stac.empty()){
            stac.push(val);
            mins.push(val);
        }
        else{
            stac.push(val);
            if(!mins.empty() && val<=mins.top())
                mins.push(val);
        }
    }

    void pop() {
        if(stac.empty())
            return;
        if(stac.top() == mins.top())
             mins.pop();
           
        
        stac.pop();
    }

    int top() {
        return stac.top();
    }

    int getMin() {
        return mins.top();
    }
    ~MinStack() {
        
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
