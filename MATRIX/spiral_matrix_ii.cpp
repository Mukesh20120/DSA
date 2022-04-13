class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top=0,left=0,right=n-1,bottom=n-1,j=1;
        vector<vector<int>>matrix(n,vector<int>(n));
        while(top<=bottom && left<=right){
            if(left>right)
                break;
            for(int i=left;i<=right;i++)
                matrix[top][i]=j++;
            top++;
            if(top>bottom)
                break;
            for(int i=top;i<=bottom;i++)
                matrix[i][right]=j++;
            right--;
            if(left>right)
                break;
            for(int i=right;i>=left;i--)
                matrix[bottom][i]=j++;
            bottom--;
            if(top>bottom)
                break;
            for(int i=bottom;i>=top;i--)
                matrix[i][left]=j++;
            left++;
        }
        return matrix;
    }
};