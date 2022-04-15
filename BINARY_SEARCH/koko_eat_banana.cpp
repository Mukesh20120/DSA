//watch neetcode for reference

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1,right=-1; //our range of answer
        for(int &it: piles)
            right=max(right,it);
        int res=right;
        while(left<=right){
            int mid=left+(right-left)/2;
            //now we find how much hour take if he eat mid no of
            //banana 
            int hour=0;
            for(int &it: piles){
                hour+=it/mid;
                if(it%mid!=0)
                    hour++;
            }
            if(hour<=h){
                res=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return res;
    }
};