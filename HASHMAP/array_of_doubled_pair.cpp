class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int>map;
        //filling the unordered map
        for(int &it: arr)
            map[it]++;
        
        //traverse throught map
       while(map.size()>0){
           int least=(*map.begin()).first;
           int target;
           //now if least is 0
           if(least==0){
               if(map[least]%2!=0)return false;
               map.erase(least);
           }
           else{
               if(least<0){
                   if(least%2!=0)return false;
                   target=least/2;
               }
               else
                   target=2*least;
               
               int mi=min(map[target],map[least]);
               if(mi==0)return false;
               map[target]-=mi;
               map[least]-=mi;
               if(!map[target])map.erase(target);
               if(!map[least])map.erase(least);
           }
       }
        return true;
    }
};