#include <bits/stdc++.h>
using namespace std;

int n, y, x, ny, nx, temp, mx=1, ret, result;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int a[104][104];
bool visited[104][104];

void dfs(int y, int x, int t){
    visited[y][x] = 1;

    for(int i=0; i<4; i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny<0 || ny>=n || nx<0 || nx>=n || a[ny][nx]<=t)continue;
        if(!visited[ny][nx]){
            dfs(ny, nx, t);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> temp;
            a[i][j] = temp;
            mx = max(temp, mx);
        }
    }

    for(int t=0; t<mx; t++){
        fill(&visited[0][0], &visited[0][0] + 104*104, 0);
        result = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j] > t && !visited[i][j]){
                    dfs(i, j, t);
                    result++;
                }
            }
        }
        ret = max(ret, result);
    }
    cout << ret;
}
