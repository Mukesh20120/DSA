class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.length();
        int m=num2.length();
        
        if(num1=="0" || num2=="0")
            return "0";
        
        if(num1=="1")
            return num2;
        if(num2=="1")
            return num1;
        
        vector<int>ans(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int product=(num2[j]-'0')*(num1[i]-'0');
                product+=ans[i+j+1];
                ans[i+j+1]=product%10;
                ans[i+j]+=product/10;
            }
        }
        int beg;
        string s="";
        for(beg=0;beg<ans.size();beg++){
            if(ans[beg]!=0)
                break;
        }
        for(;beg<ans.size();beg++){
            s.push_back(ans[beg]+'0');
        }
       return s;
    }
};