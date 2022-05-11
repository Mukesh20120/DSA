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

 