#include <iostream>
using namespace std;

int main(){
    int vertices,edges;
    cout<<"Enter the number of vertices and edges respectively"<<endl;
    cin>>vertices>>edges;
    //now making a vector of the vertices + 1 size
    int Arr[vertices+1][vertices+1] ={0};
    cout<<"enter number of the relation between two node"<<endl;
     int n;
     cin>>n;
    while(n--){
         int a,b;
         cin>>a>>b;
     if(a<=vertices && b<=vertices){
        Arr[a][b]=1;
        Arr[b][a]=1;
     }
    }
    for(int i=1;i<=vertices;i++){
        for(int j=1;j<=vertices;j++)
           cout<<Arr[i][j]<<" ";
    cout<<endl;
    }
    
    return 0;
}