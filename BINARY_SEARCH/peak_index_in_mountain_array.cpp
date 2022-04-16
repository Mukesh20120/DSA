class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //binary search will be optimal solution
        int s=0,n=arr.size(),e=n-1;
        while(s<e){
            //we have two case assume as ascending and descending order is given
            int mid=s+(e-s)/2;
            //case 
            if(arr[mid]>arr[mid+1])//means we are in descending order part then our ans can be the mid 
                e=mid;
            else
                s=mid+1;
        }
        return s;
    }
};