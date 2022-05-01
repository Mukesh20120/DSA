//using priority queue

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //creating unorder map and push all the element and its frequency
        unordered_map<int,int>mp;
        //filling mp with frequency
        for(int &it: nums)
            mp[it]++;
        //make priorty queue for
        priority_queue<pair<int,int>>pq;
        //vector for store answer
        vector<int>ans;
        //pushing in priority queue
        for(auto i=mp.begin();i!=mp.end();i++){
            pq.push({i->second,i->first});
            if(pq.size()>mp.size()-k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};