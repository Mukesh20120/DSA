/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int tar, MountainArray &mountainArr) {
        //step 1 finding the mountain peak
         int low=0,n=mountainArr.length(),high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid) > mountainArr.get(mid+1))
                high=mid;
            else
                low=mid+1;
        }
        //step 2 we are finding target on left side 
        int peak=low;
        low=0,high=peak;
        while(low<=high){
            int mid=low+(high-low)/2;
            int temp=mountainArr.get(mid);
            if(temp==tar)return mid;
            else if(temp<tar)
                low=mid+1;
            else
                high=mid-1;
        }
        //step 3 we are finding in the descending array on right side
        low=peak,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int temp=mountainArr.get(mid);
            if(temp==tar)return mid;
            else if(temp<tar)
                high=mid-1;
            else
                low=mid+1;
        }
        //if we not able to find the target then we have only
        //one option to return the -1
        return -1;
      
    }
};