#include <bits/stdc++.h>
using namespace std;

int a[9], sum;

// 주어진 키 값들
vector<int> v;

// 난쟁이가 아닌 것들
pair<int, int> ret;

void solve(){
    for (int i=0; i<9; i++){
        for(int j = 0; j<i; j++){
            if(sum - a[i] - a[j] == 100){
                ret = {i, j};
                return;
            }
        }
    }
}

int main(){
    // cin과 cout이 독립적으로 동작하도록
    ios_base::sync_with_stdio(false);

    // cin과 cout의 자동 플러시 끊기
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0; i<9; i++){
        cin >> a[i];
        sum += a[i];
    }

    solve();

    // ret에 담긴 2명을 제외한 나머지 7명의 값들을 v에 넣기기
    for(int i=0; i<9; i++){
        if(ret.first == i || ret.second == i){
            continue;
        }
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    for(int i : v){
        cout << i << " ";
    }
    return 0;
}
