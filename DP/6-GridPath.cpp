/**
*    Coded by :  Harsh vardhan 
**/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MODE 1000000007
#define ln '\n'

// Recursive Code
ll f(ll i,ll j,ll n,vector<string> &v, vector<vector<ll>> &dp){
    if(i>=n || i<0 || j>=n || j<0) return 0;

    if(i==n-1 && j==n-1) return v[i][j] == '.' ? 1 : 0;

    if(dp[i][j] != -1) return dp[i][j];
    ll down = v[i][j] == '.' ? f(i+1,j,n,v,dp) : 0;
    ll right = v[i][j] == '.' ? f(i,j+1,n,v,dp) : 0;

    return dp[i][j] = (down + right) % MODE;
}

void harsh(){
    ll n;cin>>n;
    vector<string> v(n);
    for(ll i = 0; i < n; i++) cin>>v[i];    

    vector<vector<ll>> dp(n+1, vector<ll> (n+1,-1));

    ll ans = f(0,0,n,v,dp);
    cout<<ans<<'\n';
}

// Tabulation Code
void harshTab(){
    ll n;cin>>n;
    vector<string> v(n);

    for(ll i = 0; i < n; i++) cin>>v[i];    

    // can move only right and down that is j+1, i+1

    vector<vector<ll>> dp(n+1, vector<ll> (n+1,0));  // dp[i][j] -> total no of path from (i,j) to lowerr right square
    
    // Transation -> dp[i][j] = dp[i+1][j] + dp[i][j+1]
    
    dp[n-1][n-1] = v[n-1][n-1] == '.' ? 1 : 0;
    for(ll i = n - 1; i >= 0; i--){
        for(ll j = n - 1; j >= 0; j--){
            if((i == n-1 && j == n-1) || v[i][j] == '*') continue;
            dp[i][j] = (dp[i+1][j] + dp[i][j] + dp[i][j+1])%MODE;
        }
    }

    cout<<dp[0][0]<<'\n';
}
 
int main(){
    harsh();
    return 0;
}
