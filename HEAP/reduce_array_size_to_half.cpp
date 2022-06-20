class Solution {
public:
    int minSetSize(vector<int>& arr) {
        //we required the pair of element and its frquency
        unordered_map<int,int>map;
        for(int &it: arr)
            map[it]++;
        //we need to push frequency in the max heap with its element
        //the queue pop max key,element
        priority_queue<pair<int,int>>q;
        for(auto &it: map)
            q.push({it.second,it.first});
        
        int ans=0;
        int removed=0;
        while(removed<arr.size()/2){
            removed+=q.top().first; //add in remove max frequency element
            q.pop();
            ans++;
        }
       return ans; 
    }
};

//in above code we dont required the element we just need frequency
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        //we required the pair of element and its frquency
        unordered_map<int,int>map;
        for(int &it: arr)
            map[it]++;
        //we need to push frequency in the max heap with its element
        //the queue pop max key,element
        priority_queue<int>q;
        for(auto &it: map)
            q.push(it.second);
        
        int ans=0;
        int removed=0;
        while(removed<arr.size()/2){
            removed+=q.top();
            q.pop();
            ans++;
        }
       return ans; 
    }
};