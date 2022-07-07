class Solution {
public:
    vector<long long> sumOfThree(long long num) {
       vector<long long>ans;
        long long s=num/3;
        if(num%3==0){
            ans.push_back(num/3-1);
            ans.push_back(num/3);
            ans.push_back(num/3+1);
        }
        return ans;
    }
};