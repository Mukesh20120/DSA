class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        //make a data structure to store the fraction value so we can check we not take duplicate in ans
        unordered_set<float>mp;
        vector<string>ans;
        //outter loop run from 1 to n-1
        //then inner loop run from i+1 to n
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                float fraction=float(i)/j;//type caste 
                //check if it already present in the map
                if(mp.find(fraction)==mp.end()){
                    ans.push_back(to_string(i)+"/"+to_string(j));
                    mp.insert(fraction);
                }
            }
        }
        return ans;
    }
};