class RandomizedSet {
    //using unordred map and vector
    vector<int>a;
    unordered_map<int,int>mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
            return false;
        else{
            //first we push in the array/vector
            a.push_back(val);
            mp[val]=a.size()-1;
            return true;
        }
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
            return false;
        else{
            //move that at the end and pop back from the array and map
            int last=a.back();//storing last element
            a[mp[val]]=a.back(); //storing last element in the delete value place
            a.pop_back();//remove last element of the vector
            mp[last]=mp[val];
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
      return a[rand()%a.size()];
    }
};



/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */