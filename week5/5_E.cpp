#include <bits/stdc++.h>
using namespace std;

int n, from, to, ans = 1;
vector<pair<int, int>> v;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> from >> to;

        // (끝나는 시간, 시작하는 시간) 쌍 저장
        v.push_back({to, from});
    }

    sort(v.begin(), v.end());
    
    from = v[0].second;
    to = v[0].first;
    
    for(int i=1; i<n; i++){
        if(v[i].second < to){
            continue;
        }
        from = v[i].second;
        to = v[i].first;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
