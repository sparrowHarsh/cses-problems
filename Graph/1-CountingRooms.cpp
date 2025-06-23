/**
*    Coded by :  Harsh vardhan 
**/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MODE 1000000007


int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool isValidIndex(int x,int y,int n,int m){
    return (x>=0 && y>=0 && x<n && y<m);
}

void dfs(int x,int y,vector<string> &v,vector<vector<int>> &visited){
    visited[x][y] = 1;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];

        if(isValidIndex(nx,ny,v.size(),v[0].size()) && !visited[nx][ny]){
            dfs(nx,ny,v,visited);
        }
    }
}

void harsh(){
    ll n,m;cin>>n>>m;

    vector<string> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    // Total number of rooms -> total no of connected components
    int ans = 0;
    vector<vector<int>> visited(n, vector<int> (m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == '#') visited[i][j] = 1;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                ans++;
                dfs(i,j,v,visited);
            }
        }
    }

    cout<<ans<<'\n';
}
 
 
int main(){
    harsh();
    return 0;
}