#include <bits/stdc++.h>
using namespace std;
#define y1 aaa;

int n, m, a[54][54], result = 987654321;
vector<pair<int, int>> home, chicken;
vector<vector<int>>chickenList;

void combi(int start, vector<int> v){
    if(v.size() == m){
        chickenList.push_back(v);
        return;
    }

    for(int i=start+1; i<chicken.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 빈 칸 0, 집 1, 치킨집 2
    // m개 골랐을 때 가능한 치킨 거리 합의 최솟값
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            
            if(a[i][j] == 1){
                home.push_back({i, j});
            }
            if(a[i][j] == 2){
                chicken.push_back({i, j});
            }
        }
    }

    vector<int> v;
    combi(-1, v);

    for(vector<int> cList : chickenList){
        int ret = 0;
        for(pair<int, int> _home : home){
            int mn = 987654321;
            for(int c : cList){
                int val = abs(_home.first - chicken[c].first) + abs(_home.second - chicken[c].second);
                mn = min(mn, val);
            }
            ret += mn;
        }
        result = min(result, ret);
    }
    cout << result << "\n";
}
