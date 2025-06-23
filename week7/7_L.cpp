#include <bits/stdc++.h>
using namespace std;

int n, temp, dp[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<int> l, j;

    for(int i=0; i<n; i++){
        cin >> temp;
        l.push_back(temp);
    }

    for(int i=0; i<n; i++){
        cin >> temp;
        j.push_back(temp);
    }

    for(int i=0; i<n; i++){
        for(int k=100; k>l[i]; k--){
            dp[k] = max(dp[k], dp[k - l[i]] + j[i]);
        }
    }

    cout << dp[100];
}
