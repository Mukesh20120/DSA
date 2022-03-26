// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    //first we make a map and store the pat character in the map
	    //character and its frequency
	    unordered_map<char,int>mp;
	    for(char c: pat)
	     mp[c]++;
	     
	    int count=pat.length();
	    int k=count;
	    int n=txt.length();
	    int j=0,ans=0;
	    for(int i=0;i<=n-k;i++){
	        int temp=count;
	        j=i;
	        while(j<i+k){
	            if(mp.find(txt[j])!=mp.end()){
	                temp--;
	            }
	            j++;
	        }
	        if(!temp)
	          ans++;
	    }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends