//recursion approach referance from algorithms made easy yt channel
class Solution {
public:
    bool isPossible(vector<int>& target) {
        //we need total sum and the index of maximum value
        long sum=0;
        int maxi=0;
        for(int i=0;i<target.size();i++){
            sum+=target[i];
            if(target[maxi]<target[i])
                maxi=i;
        }
        
          long diff=sum-target[maxi];
        
        //base cases
        if(target[maxi]==1 || diff==1)return true; //means all element are 1
        if(diff>target[maxi] || diff==0 || target[maxi]%diff==0)return false;
        
        target[maxi]%=diff;
        return isPossible(target);
    }
};

//optimized with the priority queue
class Solution {
public:
    bool isPossible(vector<int>& target) {
        //we need total sum and the index of maximum value
        long sum=0;
        priority_queue<int>p;
        for(int i=0;i<target.size();i++){
            sum+=target[i];
           p.push(target[i]);
        }
        
        while(p.top()!=1){
            int value=p.top();
            p.pop();
          long diff=sum-value;
        //base cases
        if(value==1 || diff==1)return true; //means all element are 1
        
        if(diff>value || diff==0 || value%diff==0)return false;
       
        value%=diff;
            sum=diff+value;
            p.push(value);
        }
        return true;
    }
};