class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        //unordered map
        int ans=INT_MAX;
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            if(map.find(cards[i])!=map.end()){
                ans=min(ans,i-map[cards[i]]+1);
            }
            map[cards[i]]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};

//using array to store the index of the element

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        //making array initilize it with 0 store the index
        int map[1000001]={0};
        int res=INT_MAX;
        for(int i=0;i<cards.size();i++){
            int c=cards[i];
            if(map[c]>0){
              res=min(res,i-map[c]+2);  
            }
            map[c]=i+1;
        }
        if(res<INT_MAX)
            return res;
        return -1;
    }
};