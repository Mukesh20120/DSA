class Solution {
    private:
     vector<int>temp;
    int h;
public:
    Solution(vector<int>& nums) {
        temp=nums;
        h=nums.size();
    }
    
    vector<int> reset() {
        return temp;
    }
    
    vector<int> shuffle() {
        vector<int>ans=temp;
       int left=h;
        for(int i=h-1;i>=0;i--){
            int j=rand()%left;
            swap(ans[i],ans[j]);
            left--;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */