//brute force approach insertion sort taking m*n time complexity
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            int x=nums2[i];
            int j=m-1;
            while(j>=0 && nums1[j]>x){
                nums1[j+1]=nums1[j];
                j--;
            }
            nums1[j+1]=x;
            m++;
        }
    }
};

//optimal solution using m+n time complexity
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=m-1;
        int b=n-1;
        int i=m+n-1;
        //checking from last and 
        while(a>=0 && b>=0){
            if(nums1[a]>nums2[b])
                nums1[i--]=nums1[a--];
            else
               nums1[i--]=nums2[b--]; 
        }
        
        //other case is b is longer than the nums1 then
        while(b>=0)
            nums1[i--]=nums2[b--];
    }
};