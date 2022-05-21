//we are making vector store the no. of index of weight

class Solution {
    vector<int>temp;
public:
    Solution(vector<int>& w) {
      for(int i=0;i<w.size();i++){
          for(int j=1;j<=w[i];j++){
              temp.push_back(i);
          }
      }
       
    }
    
    int pickIndex() {
        int l=rand()%temp.size();
        return temp[l];
    }
};


//optimal solution using binary search store the last index and implement the binary search

class Solution {
    private:
    vector<int>sum;
    int maxi;
public:
    Solution(vector<int>& w) {
        //filling the sum vector
        sum=w;
        for(int i=1;i<w.size();i++){
            sum[i]+=sum[i-1];
        }
        maxi=sum[sum.size()-1];
        
    }
    
    int pickIndex() {
        //we do binary search here
        //generate a random no. in range of maxi
        int l=1+rand()%maxi;
        int low=0,high=sum.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(sum[mid]==l)
                return mid;
            if(sum[mid]>l)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};


