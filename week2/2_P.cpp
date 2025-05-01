#include <bits/stdc++.h>
using namespace std;

int m, n, ret, a[10][10], visited[10][10];
vector<pair<int, int>> virusList, wallList;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx] || a[ny][nx] == 1){
            continue;
        }
        
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }
    return;
}

int solve(){
    // visited 배열의 모든 값들을 0으로 초기화
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);

    // 각 virus를 시작점으로 해서 dfs 수행
    // virus가 있는 곳들을 visited에 1의 값으로 표시
    for(pair<int, int> b : virusList){
        visited[b.first][b.second] = 1;
        dfs(b.first, b.second);
    }

    // 안전 영역(빈칸이면서 방문하지 않은 영역) 크기 구하기
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 0 && !visited[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    // 0 빈칸, 1 벽, 2 바이러스
    cin >> n >> m;  // 세로 n, 가로 m
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];

            if(a[i][j] == 2){
                virusList.push_back({i, j});
            }

            if(a[i][j] == 0){
                wallList.push_back({i, j});
            }
        }
    }


    // 벽 3개 세우고 안전 영역 크기 구하기
    for(int i=0; i<wallList.size(); i++){
        for(int j=0; j<i; j++){
            for(int k=0; k<j; k++){
                a[wallList[i].first][wallList[i].second] = 1;
                a[wallList[j].first][wallList[j].second] = 1;
                a[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, solve());
                a[wallList[i].first][wallList[i].second] = 0;
                a[wallList[j].first][wallList[j].second] = 0;
                a[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }
    cout << ret << '\n';
    return 0;
}
