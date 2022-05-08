/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    private:
     vector<int>output;
    int i=0;
public:
    void helper(vector<NestedInteger>& nest){
        //we have two test case
        for(int i=0;i<nest.size();i++){
            //first if the first element is single number
          if(nest[i].isInteger()){
              output.push_back(nest[i].getInteger());
          }
            else{
                helper(nest[i].getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        //we made a function to call again and again
        helper(nestedList);
    }
    
    int next() {
        int x=output.at(i);
        i++;
        return x;
    }
    
    bool hasNext() {
        return i!=output.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */