//think it as how you will implement stack structure in queue
//in other word arrange the element in queue as stack using another queue

class MyStack {
    private:
      queue<int>q1,q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        //we will push element in queue q2
        q2.push(x);
        //move every element of q1 form top to q2
        while(!q1.empty()){
            int x=q1.front();
            q2.push(x);
            q1.pop();
        }
        //swap the queue
        swap(q1,q2);
    }
    
    int pop() {
        int x=q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};


//implement using single queue

class MyStack {
    queue<int>q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        //we push the given element 
        q.push(x);
        //now we take each element from top and push it back remian x
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int t=q.front();
        q.pop();
        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

