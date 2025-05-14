/**
*    Coded by :  Harsh vardhan 
**/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MODE 1000000007LL


void harsh(){
    ll n;cin>>n;
    if(n<10){
        cout<<1<<'\n';
        return;
    }
    vector<ll> dp(n+1,1e9);
    for(ll i=1;i<10;i++) dp[i] = 1;

    for(ll num = 10; num <= n; num++){
        string str = to_string(num);
        for(auto i:str){
            ll val = i - '0';
            dp[num] = min(1 + dp[num - val], dp[num]);
        }
    }

    cout<<dp[n]<<'\n';
}
 
int main(){
    harsh();
    return 0;
}
