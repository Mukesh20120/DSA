class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pro, string sw) {
        //sort the given string vector
        sort(pro.begin(),pro.end());
        //we return answer
        vector<vector<string>>ans;
        //traverse through the given string one character at a time
        string cur="";
        for(char &c: sw){
            //add every character one by one
            cur+=c;
            //temp vector to store string
            vector<string>temp;
            auto it=lower_bound(pro.begin(),pro.end(),cur); //it gave the pointer to that word or above
            //just traverse through that point and add next 3 string in temp vector if have 
            for(int i=0;i<3 && it+i!=pro.end();i++){
                string &s=*(it+i);
                if(s.find(cur))break; //match means further is other string with different prifix
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};