//brute force approach

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>ans(n+1,0);
        ans[n]=1;
        for(int i=n-1;i>=0;i--){
            int sum=digits[i]+ans[i+1];
            ans[i+1]=sum%10;
            ans[i]=sum/10;
        }
      reverse(ans.begin(),ans.end());
        for(int i=n;i>=0;i--)
            if(ans[i]==0)
                ans.pop_back();
             else
                 break;
              reverse(ans.begin(),ans.end());
        return ans;
    }
};


//optimal solution
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>ans;
        int carry=1;
        for(int i=n-1;i>=0;i--){
            int sum=digits[i]+carry;
            ans.push_back(sum%10);
            carry=sum/10;
        }
        if(carry)
            ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};