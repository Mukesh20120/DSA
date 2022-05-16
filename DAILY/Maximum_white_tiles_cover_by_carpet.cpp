class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
        //sort the tiles vector
        sort(tiles.begin(),tiles.end());
        int n=tiles.size();
        
        //make a array that hold prefix sum
        int prefix[n+1];
        int et[n]; //it will store the end point of range of every tiles vector
        prefix[0]=0;
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+tiles[i][1]-tiles[i][0]+1;
            et[i]=tiles[i][1];
        }
        
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int start=tiles[i][0];
            int end=start+len-1;
            
            int ind=upper_bound(et,et+n,end)-et;
            
            int tsum=prefix[ind]-prefix[i]; //it will store the cover white tiles
            
            if(ind<n && end>=tiles[ind][0])
              tsum+=end-tiles[ind][0]+1;
            
            ans=max(ans,tsum);
        }
        return ans;
    }
};