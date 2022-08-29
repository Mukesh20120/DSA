//bulb question given 0 and 1 going from left to right if find 0 change it and flip the right side of every bits and cost for flip 0 is 1 count no of flip required

int Solution::bulbs(vector<int> &A) {
    int cost=0;
    for(int &b: A){
        if(cost%2==0)
          b=b;
        else
          b=!b;
          
        if(b==1)
          continue;
        else 
          cost++;
    }
    return cost;
}



//easy question find the max product of 3 no from array

//optimal solution
int Solution::maxp3(vector<int> &A) {
    //sort the array
    sort(A.begin(),A.end());
    //now we have two case we take max of both
    // 1 when two negative multiply it become +ve and last value
    // 2 last 3 values multiply with each other

    int n=A.size();
    return max(A[0]*A[1]*A[n-1],A[n-1]*A[n-2]*A[n-3])
}



//disjoint intervals 
//given intervals find non overlaping intervals 

static bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}

int Solution::solve(vector<vector<int> > &A) {
    //sort according to there ending value so we can find small range
    sort(A.begin(),A.end(),cmp);
    //ans initilize from 1 as we take the smallest interval in our ans
    int ans=1;
    //prev start and end parameter
    int  prev_st,prev_en=A[0][1];
    //run a loop from in vector
    for(auto it: A){
        //start of current is less then prev_en means that they overlap
        if(it[0]<=prev_en)
          continue;
          //we found  a range that is not overlap
        else{
            prev_st=it[0];
            prev_en=it[1];
            ans++;
        }
    }
    return ans;
}


//largest permutation 
//we can swap any number the swap time given swap and make array maximum value

vector<int> Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    //creating a hash map store the index of the current element
    int hash[n+1];
    for(int i=0;i<n;i++)
       hash[A[i]]=i;
    //starting value must be greater maxi 
    int maxi=n,i=0;
    while(i<n && B){
      int j=hash[maxi];
      if(i!=j){
          B--;
          swap(A[i],A[j]);
          //we need to update our hash map also
          swap(hash[A[i]],hash[A[j]]);
      }
      i++;
      maxi--;
    }
    return A;
}


//meeting room 
//finding the maximum room required for meeting means the maxi no of meeting
//time overlap
//optimal solution

int Solution::solve(vector<vector<int> > &A) {
    //optimal solution 
    //store the metting time and value as
    // start = +1 means 1 room required 
    // end =-1 means 1 meeting end 
    vector<pair<int,int>>mp;
    for(auto it: A){
        mp.push_back({it[0],1});
        mp.push_back({it[1],-1});
    }
    //now sort the mp according to time
    sort(mp.begin(),mp.end());
    //traverse through the mp and find max value
    int cur=0;
    int maxi=-1;
    for(auto it: mp){
        cur+=it.second;
        maxi=max(cur,maxi);
    }
    return maxi;
}

//candy distrubution 
//give extra candy to neighbour 
//ex 1 3 5 1 -> candy 1 2 3 1=7 candy
//ex 1 5 2 1 ->candy 1 3 2 1=7 candy

int Solution::candy(vector<int> &A) {
     int n=A.size();
     int ltor[n]={0},rtol[n]={0};
     ltor[0]=1;
     for(int i=1;i<n;i++){
         if(A[i-1]<A[i])
           ltor[i]+=ltor[i-1]+1;
        else
          ltor[i]=1;
     }
     rtol[n-1]=1;
     for(int i=n-2;i>=0;i--){
         if(A[i+1]<A[i])
           rtol[i]+=rtol[i+1]+1;
        else
          rtol[i]=1;
     }
     int ans=0;
     for(int i=0;i<n;i++){
         ans+=max(rtol[i],ltor[i]);
     }
     
     return ans;
}

//seats 
//store the position and find the meadian 

int Solution::seats(string A) {

    int n=A.length();
    vector<int>pos;
    //push all the position of x 
    for(int i=0;i<n;i++)
       if(A[i]=='x')
        pos.push_back(i);
    //now finding the meadian
    int len=pos.size();
    if(len==0)return 0;
    //meadian
    int med=len/2;
    int meadian=pos[med];
    int leftpos=meadian-1,rightpos=meadian+1;
    //now we calculate ans for  left side from meadian
    int ans=0;
    int mod=1e7+3;
    for(int i=med-1;i>=0;i--){
        ans=(ans+leftpos-pos[i])%mod;
        leftpos--;
    }
    for(int i=med+1;i<len;i++){
        ans=(ans+pos[i]-rightpos)%mod;
        rightpos++;
    }
     return ans; 
}



//find majority element 
//array have  n/2 more same element find the element which occur n/2 more

//other solution bit manipulation arrange the no in binary form
//and the ans =0
//now take 1st pos bit find the majority then our 1st pos must be majority
//same for 2nd pos 
//and so on


//some how i remember the approach there is many solution for this
//optimal solution

int Solution::majorityElement(const vector<int> &A) {
    int cur=A[0];
    int cnt=1;
    for(int i=1;i<A.size();i++){
        if(cur==A[i])
           cnt++;
        else{
            cnt--;
            if(cnt==0){
                cur=A[i];
                cnt=1;
            }
        }
    }
    return cur;
}

//assing mice and hole 
//make a line and put both on the of better understanding
//ex= [-4,2,3] and [0,-2,4]
//on line from -4 to 4 

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int ans=0;
    for(int i=0;i<A.size();i++){
        ans=max(ans,abs(A[i]-B[i]));
    }
    return ans;
}


//gas station 
//given two array a and b and a have gas and b have distance to travel next 
//station that means cur=cur+A[i]-B[i]; remain gas 
//not optimal soltion as due to const we are created another array of 2n size

int Solution::canCompleteCircuit( const vector<int> &A1,const vector<int> &B1) {
    vector<int>A=A1,B=B1;
    int n=A.size();
    //for rotation we are taking inserting one more time vectors
    for(int i=0;i<n;i++){
        A.push_back(A[i]);
        B.push_back(B[i]);
    }
    
    int cur,start=0;
    while(start<n){
        cur=0;
        for(int i=start;i<=start+n;i++){
            //we reach at same gas station
            if(i==start+n)
              return start;
              
            cur=cur+A[i]-B[i];
            
            if(cur<0){
                start=i+1;
              break;
            }
        }
    }
    return -1;
}



