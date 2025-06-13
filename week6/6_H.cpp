#include <bits/stdc++.h>
using namespace std;

int t, n, m, a;

int check(int a, vector<int> &v){
    int l = 0;
    int r = v.size() - 1;
    int mid;
    
    while(l <= r){
        mid = (l + r) / 2;
        
        if(v[mid] > a){
            r = mid - 1;
        }
        else if(v[mid] == a){
            return 1;
        }
        else{
            l = mid + 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
  
    cin >> t;

    while(t--){
        cin >> n;
        vector<int> v;
        for(int i=0; i<n; i++){
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());

        cin >> m;
        for(int i=0; i<m; i++){
            cin >> a;
            cout << check(a, v) << '\n';
        }
    }
    return 0;
}
