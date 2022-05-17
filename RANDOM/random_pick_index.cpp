//brute force approach using other vector to store then index and then we
//use random function
class Solution {
    private:
    vector<int>temp;
public:
    Solution(vector<int>& nums) {
        //we made a temp array and now we copy all element in it
        swap(nums,temp);
    }
    
    int pick(int target) {
        //we make another vector to store all the indicies of target
        vector<int>indicies;
        for(int i=0;i<temp.size();i++)
            if(temp[i]==target)
                indicies.push_back(i);
        //now we required size of indicies vector
        int l=indicies.size();
        int randomindex=indicies[rand()%l];
        return randomindex;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

//better approach using hashmap

class Solution {
    private:
    //store the frequency and vector of all its index
    unordered_map<int,vector<int>>mp;
public:
    Solution(vector<int>& nums) {
        //filling the unordered map
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        
    }
    
    int pick(int target) {
        //we required size of the target vector
        int l=mp[target].size();
        int randomindex=mp[target][rand()%l];
        return randomindex;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */


//optimal solution but giving tle
class Solution {
public:
    
    vector<int> nums;
    
    Solution(vector<int>& nums) {
        this->nums.swap(nums);
    }
    
    int pick(int target) {
        int n = nums.size();
        int count = 0;
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            // if nums[i] is equal to target, i is a potential candidate
            // which needs to be chosen uniformly at random
            if (nums[i] == target) {
                // increment the count of total candidates
                // available to be chosen uniformly at random
                count++;
                // we pick the current number with probability 1 / count (reservoir sampling)
                if (rand() % count == 0) {
                    idx = i;
                }
            }
        }
        return idx;
    }
};