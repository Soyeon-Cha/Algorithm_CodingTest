#include <bits/stdc++.h>
using namespace std;

int n, m, temp, dp[41], cnt[41];

int go(int pos){
    if(pos >= n-1){
        return 1;
    }

    if(cnt[pos]){
        return go(pos + 1);
    }

    if(dp[pos] != -1){
        return dp[pos];
    }

    dp[pos] = 0;
    
    if(!cnt[pos + 1]){
        dp[pos] += (go(pos + 2) + go(pos + 1));
    }
    else{
        dp[pos] += go(pos + 1);
    }
    return dp[pos];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> temp;
        cnt[temp - 1] = 1;
    }

    fill(dp, dp + 41, -1);
    cout << go(0);
    return 0;
}
