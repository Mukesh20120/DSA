//things need to remember
//edge case first and last cut 0 to h[0] and total-lastelement of h
//find maxi of all 
//store in long long
//type case in int to return it

class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        long hmax=hc[0];
        for(int i=1;i<hc.size();i++)
            if(hmax<(hc[i]-hc[i-1]))
                hmax=hc[i]-hc[i-1];
        //checking last from total edge to last index
        if(hmax<(h-hc[hc.size()-1]))
            hmax=h-hc[hc.size()-1];
        
        //same for vertical cut 
         sort(vc.begin(),vc.end());
        long vmax=vc[0];
        for(int i=1;i<vc.size();i++)
            if(vmax<(vc[i]-vc[i-1]))
                vmax=vc[i]-vc[i-1];
        //checking last from total edge to last index
        if(vmax<(w-vc[vc.size()-1]))
            vmax=w-vc[vc.size()-1];
        
        long ans=(hmax*vmax)%1000000007;
        return (int)ans;
    }
};