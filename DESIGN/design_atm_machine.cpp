class ATM {
    private:
    //make two array of for store the count of note and other its vlaue
    long long count[5],notes[5]={20,50,100,200,500};
public:
    ATM() {
        for(int i=0;i<5;i++)
            count[i]=0;
    }
    
    void deposit(vector<int> banknotesCount) {
        //we just fill the count array same as banknotes count given vector
        for(int i=0;i<banknotesCount.size();i++){
            //adding more note in count array that store the note that already have
            count[i]+=banknotesCount[i];
        }
        
    }
    
    vector<int> withdraw(int amount) {
        //we check if the amount can be reduce to 0 by notes we have
        vector<int>ans(5,0);
        for(int i=4;i>=0;i--){
            //total no of node we take
            ans[i]=min(amount/notes[i],count[i]);
            amount-=ans[i]*notes[i];
        }
        //remain amount we not able to do it
        if(amount){
            return {-1};
        }
        else{
            for(int i=4;i>=0;i--)
               count[i]-=ans[i];
        }
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */