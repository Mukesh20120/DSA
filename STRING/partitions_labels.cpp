class Solution {
public:
    vector<int> partitionLabels(string s) {
        //making a bit masking to store the last occurance
        vector<int>last_occ(26,0);
        for(int i=0;i<s.length();i++)
            last_occ[s[i]-'a']=i;
        //storing result
        vector<int>ans;
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
            end=max(end,last_occ[s[i]-'a']);
            //we find the last occ of any character we add it to our
            //result
            if(i==end){
                ans.push_back(i-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};