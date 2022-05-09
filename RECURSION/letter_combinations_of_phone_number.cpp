class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0)
            return ans;
        //our string array
        string nums[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv",
                       "wxyz"};
        //passing into the function and fill the ans
        //answers vector,index,temp string,given digit
        combination(ans,nums,0,"",digits);
     return ans;       
    }
    void combination(vector<string>&ans,string nums[],int i,string s,string digits){
        //base case 
        if(i==digits.length()){
            ans.push_back(s);
            return;
        }
        string val=nums[digits[i]-'0'];
        for(int k=0;k<val.length();k++){
            combination(ans,nums,i+1,s+val[k],digits);
        }
    }
};