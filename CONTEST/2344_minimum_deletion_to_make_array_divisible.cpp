//brute force approach using priority queue and unordered map
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& nd) {
        
        //unordered_map to store the frequency and the nums
        unordered_map<int,int>mp;
        for(int &i: nums)
            mp[i]++;
        
        //now push all the unique element of map in mini priority queue
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto &it: mp)
            q.push(it.first);
        
        int ans=0;
        while(!q.empty()){
            int s=q.top();
            bool flag=false;
            for(int i=0;i<nd.size();i++){
                if(nd[i]%s!=0){
                    flag=true;
                    break;
                }
            }
            if(!flag)
                return ans;
           
                ans+=mp[s];
                q.pop();
        }
        return -1;
    }
};


//optimal solution
class Solution {
public:
  
    int minOperations(vector<int>& nums, vector<int>& nd) {
        int g=nd[0];
        for(int i=0;i<nd.size();i++)
            g=gcd(g,nd[i]); //finding gcd from nd array
        sort(nums.begin(),nums.end());  //sort the nums to find mini deletion
        for(int i=0;i<nums.size();i++)
            if(g%nums[i]==0)
                return i;
        return -1;
    }
};