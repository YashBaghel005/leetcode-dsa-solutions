class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            int a = st1.top();
            st1.pop();
            st2.push(a);
        }
        int a = st2.top();
        st2.pop();
        while(!st2.empty()){
            int b = st2.top();
            st2.pop();
            st1.push(b);
        }
        return a;
    }
    
    int peek() {
        while(!st1.empty()){
            int a = st1.top();
            st1.pop();
            st2.push(a);
        }
        int a = st2.top();
        // st2.pop();
        while(!st2.empty()){
            int b = st2.top();
            st2.pop();
            st1.push(b);
        }
        return a;
    }
    
    bool empty() {
        if(st1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */