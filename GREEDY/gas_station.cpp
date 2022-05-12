class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //brute force appraoch using two loop
        int n=gas.size(); //size of gas station
        //two nested loop
        for(int i=0;i<n;i++){
            //total maintain the sum,j for traversal,stop count the circle circuit
            int total=0,j=i,stop=0;
            //another loop
            while(stop<n){
                total+=gas[j%n]-cost[j%n]; //cost and the gas filled in total
                //if total is negative then we break the loop
                if(total<0)
                    break;
                stop++,
                j++;
            }
            //after loop end we need to check if it come from break or loop end due to below condition
            if(stop==n && total>=0)
                return i;
        }
        return -1;
    }
};


//optimal solution one traversal

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank=0,total=0,index=0;
        for(int i=0;i<gas.size();i++){
            int consume=gas[i]-cost[i];
            tank+=consume;
            if(tank<0){
                index=i+1;
                tank=0;
            }
            total+=consume;
        }
        return total<0?-1:index;
    }
};