 class SeatManager {
    private:
      priority_queue<int,vector<int>,greater<int>>q;
public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
            q.push(i);
    }
    
    int reserve() {
        int x=q.top();
        q.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

//optimal solution using  another variable to we just pushing the unresered seat in queue
class SeatManager {
    private:
      int m;
    priority_queue<int,vector<int>,greater<int>>q;
public:
    SeatManager(int n) {
        m=0;
    }
    
    int reserve() {
        if(q.empty()){
            m++;
            return m;
        }
        int x=q.top();
        q.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        q.push(seatNumber);
    }
};

