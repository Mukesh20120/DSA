//same pattern as multiply string question

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        int n=num.size()-1;
        int carry=0;
        while(n>=0 || k || carry){
            if(n>=0)
                carry+=num[n--];
            if(k){
                carry+=(k%10);
                k=k/10;
            }
            ans.push_back(carry%10);
            carry=carry/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};