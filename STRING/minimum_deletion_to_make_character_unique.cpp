class Solution {
public:
    int minDeletions(string s) {
        //making a frequency table 
        int freq[26]={0};
        for(char &c: s)
            freq[c-'a']++;
        //algorithm 1 we store the frequency in set hashset
        unordered_set<int>hash;
        int i=0;
        int del=0;
       for(int i=0;i<26;i++){
           while(freq[i] && hash.find(freq[i])!=hash.end()){
               freq[i]--;
               del++;
           }
           hash.insert(freq[i]);
       }
        return del;
    }
};

//using priority queue to push 

class Solution {
public:
    int minDeletions(string s) {
        //other approach using priority queue
        priority_queue<int>q;
        //inserting the frequency in priority queue
        int freq[26]={0};
        for(char &c: s)
            freq[c-'a']++;
        for(int i=0;i<26;i++)
            if(freq[i]>0)
              q.push(freq[i]);
        //now we empty the queue by comparing two top element and if
        //it is same we decrease one of frequecny and insert back in 
        //queue
       int del=0;
        while(q.size()>1){
            int t=q.top();
            q.pop();
            if( t==q.top()){
                if(t-1>0)
                    q.push(t-1);
               del++;
            }
           
        }
        return del;
    }
};


//optimal solution 
class Solution {
public:
    int minDeletions(string s) {
        //store the frequency
        vector<int>freq(26,0);
        for(char &c: s)
            freq[c-'a']++;
        //sort the freq array in decreasing order
        sort(freq.begin(),freq.end(),greater<int>());
        //now we need to iterate through  it
        int maxfreq=s.length();
        int del=0;
        for(int i=0;i<26 && freq[i]>0;i++){
            if(freq[i]>maxfreq){
                del+=(freq[i]-maxfreq);
                freq[i]=maxfreq;
            }
            maxfreq=max(0,freq[i]-1);
        }
        return del;
    }
};