class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //binary search we return start when it cross the start and end the last 
        //position of start is our answer just module it to make return 1 if start equal to n length
        int start=0,n=letters.size(),end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(letters[mid]<=target)
                start=mid+1;
            else
                end=mid-1;
        }
        return letters[start%n];
    }
};