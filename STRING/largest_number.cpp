//my own brute force approach
class Solution {
public:
//finding length of the number
    int getlength(int x){
        if(x==0)
            return 1;
        int cnt=0;
        while(x){
            x=x/10;
            cnt++;
        }
        return cnt;
    }
    
//making new number by adding it
    long helper(long n,int l){
        for(int i=0;i<l;i++)
            n*=10;
        return n;
    }
    
//checking two number
    bool check(int a,int b){
        int l1=getlength(a); //a=10 l1=2
        int l2=getlength(b); //b=2 l2=1
        
        if((helper(a,l2)+b)<(helper(b,l1)+a))
            return true;
        
        return false;
    }
    
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(check(nums[i],nums[j]))
                    swap(nums[i],nums[j]);
            }
        }
//for the all first 0
      int k=0;
      while(k<n && nums[k]==0)k++;
    
        string ans;
        if(k==n)
            ans="0";
        else
            ans="";
        
        for(;k<n;k++)
            ans+=to_string(nums[k]);
        
        return ans;
    }
};


//optimals solution using to string converting integer to string 
class Solution {
public:
    static bool cmp(int a,int b){
        //changing into string
        string s1=to_string(a);
        string s2=to_string(b);
        
        return s1+s2>s2+s1;
    }
    
    string largestNumber(vector<int>& nums) {
        //first sort the given vector making your own comparator
        sort(nums.begin(),nums.end(),cmp);
        string ans="";
        for(int &it: nums)
            ans+=to_string(it);
        //checking the first character is 0 or not
        if(ans[0]=='0')
            return "0";
        
        return ans;
    }
};