class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        sort(hor.begin(),hor.end());
        
        long hmax=hor[0];
        for(int i=1;i<hor.size();i++){
            if(hor[i]-hor[i-1]>hmax)
                hmax=hor[i]-hor[i-1];
        }
        if(hmax<h-hor[hor.size()-1])
            hmax=h-hor[hor.size()-1];
        
        sort(ver.begin(),ver.end());
        long rmax=ver[0];
        for(int i=1;i<ver.size();i++){
            if(rmax<ver[i]-ver[i-1])
                rmax=ver[i]-ver[i-1];
        }
        if(rmax<w-ver[ver.size()-1])
            rmax=w-ver[ver.size()-1];
       long ans=(rmax*hmax)%1000000007;
        return (int)ans;
    }
};