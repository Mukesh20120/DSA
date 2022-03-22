class Solution {
public:
    pair<int,int> cordinate(int sum,int n){
        pair<int,int>temp;
        temp.first=n-1-(sum-1)/n; //row
        temp.second=(sum-1)%n;
        if(temp.first%2==n%2)
            temp.second=n-1-temp.second;
        return temp;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        //the tricky part here is the coordinate if we know then question boil down to minimum steps
        int n=board.size();
       vector<vector<bool>>visit(n,vector<bool>(n,false));
        queue<int>q;
        int step=0;
        visit[n-1][0]=true;
        q.push(1);
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                int s=q.front();
                q.pop();
            if(s==n*n)
                return step;
            for(int i=1;i<=6;i++){
                if(s+i>n*n)break;
               pair<int,int>t=cordinate(s+i,n);
                if(visit[t.first][t.second])
                continue;
                    visit[t.first][t.second]=true;
                    if(board[t.first][t.second]==-1)
                        q.push(s+i);
                    else
                        q.push(board[t.first][t.second]);
                
                }
            }
            step++;
        }
      return -1;                            
    }
};