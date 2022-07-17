class StockPrice {
    //two unordered map one for cur time and other for 
    //maxi and mini
    int latest;
    unordered_map<int,int>tsp;
    map<int,int>freqpric;
public:
    StockPrice() {
        latest=0;
    }
    
    void update(int t, int p) {
        //update latest
        latest=max(latest,t);
        //we check if the tsp already store the price
        if(tsp.find(t)!=tsp.end()){
            //then we need to replace the price
            int oldpric=tsp[t]; //price at timestamp
            //we will decrease freq of that price
            freqpric[oldpric]--;
            if(freqpric[oldpric]<=0)
                freqpric.erase(oldpric);
        }
        tsp[t]=p;
        freqpric[p]++;
    }
    
    int current() {
        return tsp[latest];
    }
    
    int maximum() {
        return freqpric.rbegin()->first;
    }
    
    int minimum() {
        return freqpric.begin()->first;
    }
};
