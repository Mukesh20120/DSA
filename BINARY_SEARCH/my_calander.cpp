class MyCalendar {
    private:
    vector<pair<int,int>>cal;
public:
    MyCalendar() {
        
    }
    
    bool book(int l, int r) {
        for(auto it: cal){
            int s=it.first;
            int e=it.second;
            if(max(s,l)<min(e,r))
                return false;
        }
         cal.push_back({l,r});
        return true;
    }
};

//optimal 
class MyCalendar {
    private:
    map<int,int>m;
public:
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        if(m.empty()){
            m[s]=e;
            return true;
        }
        
        auto t=m.lower_bound(s);
        //t-first lie b/w s and e
        if(t!=m.end() && t->first>=s && t->first<e)
         return false;
        t--;
        if(t->first<=s && t->second>s)
            return false;
        m[s]=e;
        return true;
    }
};
