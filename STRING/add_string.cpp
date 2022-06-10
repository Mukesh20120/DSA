class Solution {
public:
    string addStrings(string num1, string num2) {
        int n=num1.length()-1;
        int m=num2.length()-1;
        int carry=0;
        string ans;
        while(n>=0 || m>=0 || carry){
            if(n>=0)
                carry+=num1[n--]-'0';
            if(m>=0)
                carry+=num2[m--]-'0';
            ans=to_string(carry%10)+ans;
            carry=carry/10;
        }
        return ans;
    }
};