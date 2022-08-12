void build(int *tree,int arr[],int i,int s,int e){
    if(s==e){
        tree[i]=arr[s];
        return;
    }
    int mid=(s+e)/2;
    build(tree,arr,2*i+1,s,mid);
    build(tree,arr,2*i+2,mid+1,e);
    
    tree[i]=min(tree[2*i+1],tree[2*i+2]);
}
int *constructST(int arr[],int n)
{
  int *tree=new int[2*n+1];
  build(tree,arr,0,0,n-1);
  return tree;
}

int query(int *st,int i,int s,int e,int l,int r){
    //3 cases
    if(r<s || e<l)
      return INT_MAX;
    if(l<=s && e<=r)
       return st[i];
    int mid=(s+e)/2;
    int q1=query(st,2*i+1,s,mid,l,r);
    int q2=query(st,2*i+2,mid+1,e,l,r);
    return min(q1,q2);
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[] , int n, int a, int b)
{
    return query(st,0,0,n-1,a,b);

}


//copy code just for refe. from gfg
int *constructST(int arr[],int n)
{
    int *tree = new int[2*n];
    for(int i=0;i<n;i++)
        tree[i+n]=arr[i];
    for(int i=n-1;i>0;i--)
        tree[i] = min(tree[i<<1],tree[i<<1 | 1]);
    return tree;
}

int RMQ(int st[] , int n, int l, int r)
{
    int ans = INT_MAX;
    r++;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1)
            ans=min(ans,st[l++]);
        if(r&1)
            ans = min(ans,st[--r]);
    }
    return ans;
}