class MedianFinder {
    private:
      vector<int>nums;
      int n;//size
public:
    MedianFinder() {
        n=0;
    }
    
    void addNum(int num) {
        nums.push_back(num);
        sort(nums.begin(),nums.end());
        n++;
    }
    
    double findMedian() {
        if(n%2==1)
            return double(nums[n/2]);
        else
            return double(nums[n/2]+nums[n/2 -1])/2;
    }
};


//optimal solution using priority queue
class MedianFinder {
    private:
    //define max heap 
    priority_queue<int>maxheap;
    //definde min heap
    priority_queue<int,vector<int>,greater<int>>minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //first we push in max heap
        maxheap.push(num);
        //pushing the top of max heap in min heap
        minheap.push(maxheap.top());
        //pop back from max heap
        maxheap.pop();
        //checking if the size of min heap is greater than max heap
        if(minheap.size()>maxheap.size()){
            //taking out from min
            maxheap.push(minheap.top());
            //empty the top element from the min 
            minheap.pop();
        }
        
    }
    
    double findMedian() {
        //now we check the test case if the max heap is greater than min then we return the maxheaptop
        if(maxheap.size()>minheap.size())
            return maxheap.top();
        return (minheap.top()+maxheap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 