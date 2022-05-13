//brute force approach 
//taking in another vector and sort the vector

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>temp;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++)
                temp.push_back(matrix[i][j]);
        sort(temp.begin(),temp.end());
        
      
        return temp[k-1];
    }
};

//using priority queue pushing k element and then pop if extra element added

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //make a priority_queue and push elements
        priority_queue<int>pq;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k)pq.pop();
            }
        }
        return pq.top();
    }
};


//optimal approach using binary search

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //binary search in range of the matrix element
        int n=matrix.size();
        //we make range from low to high
        int low=matrix[0][0],high=matrix[n-1][n-1];
        while(low<high){
            int mid=low+(high-low)/2;
            if(count(matrix,mid)<k){
                low=mid+1;
            }
            else
                high=mid;
        }
        return low;
    }
    int count(vector<vector<int>>&nums,int mid){
        //same function as in search in sorted matrix ii
        int n=nums.size(),i=n-1,j=0,cnt=0;
        //we search in up and right
        while(i>=0 && j<n){
            if(nums[i][j]>mid)
                i--;
            else
                cnt+=i+1,j++;
        }
        return cnt;
    }
};