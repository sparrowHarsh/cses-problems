/**
*    Coded by :  Harsh vardhan 
**/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MODE 1000000007LL

/*Tabulation Approach */
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

/*Recursice Approach */
ll f(ll n,vector<ll> &dp){
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];
    ll take = 1e9;
    string s = to_string(n);
    for(auto i:s){
        ll val = i - '0';
        if(n - val >= 0 && val != 0){
            take = min(take, 1 + f(n-val,dp));
        }
    }

    return dp[n] = take;
}


void harsh(){
    ll n;cin>>n;
    vector<ll> dp(n+1,-1);
    ll ans = f(n,dp);
    cout<<ans<<'\n';
}
 
int main(){
    harsh();
    return 0;
}
