#include <bits/stdc++.h>
using namespace std;

int n, c, k, a[1004];
vector<pair<int, int>> v;
map<int, int> mp, mp_first;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return mp_first[a.second] < mp_first[b.second];
    }
    return a.first > b.first;
}

int main(){
    // c 이하인, n개의 수들
    cin >> n >> c;

    // 빈도 수 정렬
    for(int i=0; i<n; i++){
        cin >> k;
        a[i] = k;
        mp[k]++;

        if(mp_first[k] == 0){
            mp_first[k] = i+1;
        }
    }
    
    for(auto it : mp){
        v.push_back({it.second, it.first});  // {등장 횟수, 수}
    }

    sort(v.begin(), v.end(), cmp);

    for(auto p : v){
        for(int j=0; j<p.first; j++){
            cout << p.second << " ";
        }
    }
    return 0;
}
