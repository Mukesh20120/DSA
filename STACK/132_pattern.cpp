//brute force approach using three nested loop
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //we will use three nested loop 
        int n=nums.size();
        if(n<3)
            return false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]<nums[k] && nums[k]<nums[j])
                        return true;
                }
            }
        }
        return false;
    }
};


//better approach using two nested loop o(n^3)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        //we will use three nested loop 
        int n=nums.size();
        if(n<3)
            return false;
        int mini=nums[0];
            for(int j=1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(mini<nums[k] && nums[k]<nums[j])
                        return true;
                }
                mini=min(mini,nums[j]);
            }
        
        return false;
    }
};


//optimal solution using stack and mini vector
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       //solving using minimum vector and stack
        //first make a min vector contain all the min element
        int n=nums.size();
        vector<int>mini(n);
        mini[0]=nums[0];
        for(int i=1;i<n;i++)
            mini[i]=min(mini[i-1],nums[i]);
        
        //now store the value in stack and traverse through back side of vector
        stack<int>st;
        for(int j=n-1;j>=0;j--){
            //checking the first case
            if(nums[j]>mini[j]){
                while(!st.empty() && st.top()<=mini[j]){
                    st.pop();
                }
                if(!st.empty() && st.top()<nums[j])
                    return true;
                st.push(nums[j]);
            }
        }
         return false; 
    }
};