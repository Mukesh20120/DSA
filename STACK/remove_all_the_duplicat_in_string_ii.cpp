class Solution {
public:
    string removeDuplicates(string s, int k) {
       //we will solve this question using vector and character and freuqency
        //declare the vector and its fequecny
          // one store the character and othe store the frequency
        vector<pair<char,int>>st; 
        //filling the vector
        for(auto c: s){
            //now here is two case when vector is empty and the previous characte is not matching
            if(st.size()==0 || st.back().first!=c) //checking each time element is new or not
                st.push_back({c,1});
            else{
                //other case is when the element is already present in the vector
                st.back().second++;
            }
            //another case is when the frequency of the last character is match the given integer k
            if(st.back().second==k)
                st.pop_back(); //remove the last character form the vector
        }
        //as our vector is filled with the character and its frequency now we just have to make 
        //a string and return  it in our answer
        string ans;
        //here is inbuild function called append the take integer and character and add it to the string 
        //back
        for(auto c: st){
            ans.append(c.second,c.first);
        }
        return  ans;
    }
};