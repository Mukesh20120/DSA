//brute force approach
class Solution {
public:
    int candy(vector<int>& ratings) {
        //brute force approach making a vector of candy
        int n=ratings.size();
        vector<int>candies(n,1);
        //run a loop until some changes happening
        bool haschange=true;
        while(haschange){
            haschange=false;
            for(int i=0;i<n;i++){
                //checking previous rating 
                if(i!=n-1 && ratings[i]>ratings[i+1] && candies[i]<=candies[i+1]){
                    candies[i]=candies[i+1]+1;
                    haschange=true;
                }
                //checking next rating
                if(i>0 && ratings[i]>ratings[i-1] && candies[i]<=candies[i-1]){
                    candies[i]=candies[i-1]+1;
                    haschange=true;
                }
            }
        }
        return accumulate(candies.begin(),candies.end(),0);
    }
};

//other solution taking extra space 

class Solution {
public:
    int candy(vector<int>& r) {
        //make two array one left2right and other right2left
        //initilize with it 1 candy in start
        int n=r.size();
        vector<int>left2right(n,1),right2left(n,1);
        //now left move left 2 right
        for(int i=1;i<n;i++){
            if(r[i]>r[i-1])
                left2right[i]=left2right[i-1]+1;
        }
        
        for(int i=n-2;i>=0;i--){
            if(r[i]>r[i+1])
                right2left[i]=right2left[i+1]+1;
        }
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=max(left2right[i],right2left[i]);
        
        return sum;
    }
};

//same above code just using 1 d array

class Solution {
public:
    int candy(vector<int>& r) {
        //make two array one left2right and other right2left
        //initilize with it 1 candy in start
        int n=r.size();
        vector<int>candies(n,1);
        for(int i=1;i<n;i++)
            if(r[i]>r[i-1])
                candies[i]=candies[i-1]+1;
        //now moving right to left
        for(int i=n-2;i>=0;i--)
            if(r[i]>r[i+1])
                candies[i]=max(candies[i],candies[i+1]+1);
        
        return accumulate(candies.begin(),candies.end(),0);
    }
};

//more optimal solution using slop method have to do