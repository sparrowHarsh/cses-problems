/**
*    Coded by :  Harsh vardhan 
**/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MODE 1000000007LL



/*Recursive Approach */
ll f(ll dice,ll sum,vector<ll> &dp){
    if(sum == 0){
        return 1;
    }

    if(sum < 0 || dice > 6) return 0;

    if(dp[sum] != -1) return dp[sum];

    ll take = f(dice, sum - dice, dp);
    ll nottake = f(dice + 1,sum,dp);

    return dp[sum] = (take + nottake) % MODE;
}


/*Tabulation Approach */
void harsh(){
    ll n;cin>>n;
    vector<ll> dp(n+1);   // dp[i] -> total number of ways of getting sum i
    dp[0] = 1;
 
    for(int sum = 1; sum <= n; sum++){
        // dice
        for(int dice = 1;dice <= 6; dice++){
            int leftSum = sum - dice;
            if(leftSum >= 0){
                dp[sum] = (dp[leftSum] + dp[sum]) % MODE;
            }
        }
    }
 
    cout<<dp[n]<<'\n';
}


void harsh(){
    ll n;cin>>n;
    vector<ll> dp(n+1,-1);
    ll ans = f(1,n,dp);
    cout<<ans<<'\n';
}
 
int main(){
    harsh();
    return 0;
}
