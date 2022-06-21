//brute force approach written by own 
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>q;
        q.push(a);
        q.push(b);
        q.push(c);
        int ans=0;
        while(1){
            int x=q.top();q.pop();
            int y=q.top();q.pop();
            if(x==0 || y==0)break;
            x--,y--;
            q.push(x);
            q.push(y);
            ans++;
        }
        return ans;
    }
};

//optimal solution don't know how it come(unable to understand)
class Solution {
public:
    int maximumScore(int a, int b, int c) {
     return min((a+b+c)/2,a+b+c-max({a,b,c}));   
    }
};