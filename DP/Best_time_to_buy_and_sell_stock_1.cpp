class Solution {
public:
    int maxProfit(vector<int>& p) {
        //storing ans maximumprofit
        int ans=0;
        //minimum cost of the stock
        int minicost=p[0];
        //running loop from 1 to n as we assume that the 1st element is minimum
        for(int i=1;i<p.size();i++){
            int cost=p[i]-minicost; //temp profit of mini and cur value
            ans=max(ans,cost); //updating max value of the profit
            minicost=min(minicost,p[i]);  //updating the minimum cost of the stock
        }
        return ans;
    }
};