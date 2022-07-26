//using hash map and sorting 
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        //losses player frequency
        sort(m.begin(),m.end());
       map<int,int>playloss;
        for(int i=0;i<m.size();i++)
            playloss[m[i][1]]++;
        
        vector<vector<int>>ans(2);
        
       for(int i=0;i<m.size();i++)
           if(playloss.find(m[i][0])==playloss.end()){
                ans[0].push_back(m[i][0]);
               //marking we have taken this player
                playloss[m[i][0]]=1000;
           }
              
           
       for(auto it: playloss)
           if(it.second==1)
               ans[1].push_back(it.first);
       
         return ans;
    }
};


//optimal solution using own hashmap

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        //finding the max and min player from the m
        //we have to find min and max from 2d vector 
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto it: m){
            //the it[0] and it[1] could be min or max
            mini=min(mini,it[0]);
            mini=min(mini,it[1]);
            maxi=max(maxi,it[0]);
            maxi=max(maxi,it[1]);
        }
        
        int n=maxi-mini+1; //size of our hashmap
        
        bool isplayer[n];
        memset(isplayer,0,sizeof(isplayer));
        int lossfreq[n];
        memset(lossfreq,0,sizeof(lossfreq));
        
        //we will traverse through the 2d array marking both is
        //player and the frequency of the loss
        for(auto it: m){
            isplayer[it[0]-mini]=true;
            isplayer[it[1]-mini]=true;
            lossfreq[it[1]-mini]++;
        }
        
        vector<vector<int>>ans(2);
        //now we just need to traverse through the lossfreq 
        //ans if it is a player and loss freq is 0 means no loss
        //and if freq is 1 we store in other vector
        
        for(int i=0;i<n;i++){
            if(!isplayer[i])
                continue;
            
            if(lossfreq[i]==0)
                ans[0].push_back(i+mini);
            else if(lossfreq[i]==1)
                ans[1].push_back(i+mini);
        }
        return ans;
    }
};