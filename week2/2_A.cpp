#include <bits/stdc++.h>
using namespace std;

const int max_n = 104;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;

int main(){
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &a[i][j]);
        }
    }

    queue<pair<int, int>> q;
    visited[0][0] = 1;  // 시작점에 visited 1 걸기
    q.push({0, 0});
    
    while(q.size()){  // queue에 요소가 존재하는 한
        tie(y, x) = q.front();  // pop하기 전에 할당
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 참조하기 전 컨테이너 외부에 있는지 확인, 방문할 수 없는 지점인지 확인
            if(ny<0 || ny>=n || nx<0 || nx>=m || a[ny][nx]==0){
                continue;
            }

            if(visited[ny][nx]){
                continue;
            }

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    printf("%d", visited[n-1][m-1]);
    return 0;
}
