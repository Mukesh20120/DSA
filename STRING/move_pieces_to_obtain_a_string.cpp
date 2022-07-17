class Solution {
public:
    bool canChange(string start, string target) {
        //make a vector store the index of L and R
        vector<int>lri;
        for(int i=0;i<start.size();i++)
            if(start[i]!='_')
            lri.push_back(i);
        int i=0;
        //now we traverse through target and if we encounter l or r
        //we check with the start and i++
        for(int j=0;j<target.size();j++){
            if(target[j]=='L' || target[j]=='R'){
                //first check for i not gone its outof bound
                if(i>=lri.size() || target[j]!=start[lri[i]])
                    return false;
                else{
                    //we have two case of check right and left
                    if(target[j]=='L' && lri[i]<j)
                        return false;
                    if(target[j]=='R' && lri[i]>j)
                        return false;
                }
                i++;
            }
        }
        return i==lri.size();
    }
};