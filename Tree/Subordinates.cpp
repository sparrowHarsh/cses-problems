/**
*    Coded by :  Harsh vardhan 
**/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int


/*
Decide the recursive funciton first. whether it would be a void or a type of int
Be clear with the base condition
*/

ll dfs(ll root, vector<ll> adj[], vector<bool> &isVisited, vector<ll> &subOrdinate){
    isVisited[root] = true;
    ll totalChild = 0;
    for(auto child:adj[root]){
        if(!isVisited[child]){
            totalChild += 1 + dfs(child,adj,isVisited,subOrdinate);
        }
    }
    subOrdinate[root] = totalChild;
    return totalChild;
}

void harsh(){
    ll n;cin>>n;
    vector<ll> v(n+1);

    for(ll i = 2; i <=n; i++) cin>>v[i];

    vector<ll> adj[n+1];
    for(ll i=2;i<=n;i++){
        adj[v[i]].push_back(i);
    }

    vector<ll> subOrdinate(n+1,0);
    vector<bool> isVisited(n+1,false);

    dfs(1,adj,isVisited,subOrdinate);
    for(int i=1;i<=n;i++) cout<<subOrdinate[i]<<' ';
    cout<<'\n';
}

int main(){
    harsh();
    return 0;
}
