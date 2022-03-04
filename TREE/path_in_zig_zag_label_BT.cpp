class Solution {
public:
    vector<int> pathInZigZagTree(int n) {
        //finding the start and the last point of the row of binary tree
      int llh=1;
      int cur=0;
        while(cur<=n){
            cur=2*llh;
            llh*=2;
        }
        llh/=2; //start point
        vector<int>ans; //store ans
        int parent;  //we are going from bottom to up 
        while(n>=1){
            ans.push_back(n);
            parent=(cur-n+llh-1)/2; //what value will be swaped from it
            n=parent; //changing 
            cur/=2; //reset the start and the end point
            llh/=2;
        }
        reverse(ans.begin(),ans.end()); //ans store in reverse order reverse it to return it
        
        return ans;
    }
};