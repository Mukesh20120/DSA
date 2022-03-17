class Solution {
    int di[4]={-1,0,+1,0};
    int dj[4]={0,+1,0,-1};
public:
    void change(int i,int j,int x,vector<vector<int>>&img,int newcolor,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || img[i][j]!=x)return;
        img[i][j]=newcolor;
        for(int ind=0;ind<4;ind++){
            change(i+di[ind],j+dj[ind],x,img,newcolor,n,m);
        }
            
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        int x=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        if(x!=newcolor)
          change(sr,sc,x,image,newcolor,n,m);
        return image;
    }
};