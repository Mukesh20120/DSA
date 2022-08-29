#define ll long long

#include <bits/stdc++.h>
using namespace std;


/***************TLE soution***************************/
//changing in the number and also checking the power of the
//number
inline bool change(string s){
    cout << s << endl;
    int ans = 0;
    for (int i = 0; i < s.length();i++){
        ans = ans * 10 + (s[i] - '0');
        if(ans==0)
            return false;
    }

    return ans && !(ans & (ans - 1));
}

//permutaion of the number 
bool arrangement(string num,int k){
    if(change(num))
        return true;
    for (int i = k; i < num.length();i++){
        for (int j = i+1; j < num.length();j++){
            swap(num[i], num[j]);
            arrangement(num,k+1);
            swap(num[i], num[j]);
            //  return true;
        }
    }
    return false;
}
/***************TLE soution***************************/


/*************optimal solution**********************/

vector<int> count(int n){
    vector<int> A(10);
    while(n){
        A[n % 10]++;
        n /= 10;
    }
    return A;
}
bool helper(int n){
    vector<int> A = count(n);
    for (int i = 0; i < 32;i++){
        if(A==count(1<<i))
            return true;
    }
    return false;
}
/*************optimal solution**********************/

void solve()
{
    int n;
    cin >> n;
    //all arrangement without leading 0
    // string num = to_string(n);
    // cout<<arrangement(num,0)<<endl;
    cout << helper(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    auto start = clock();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    auto end = clock();
    //cout << end - start << endl;

    return 0;
}