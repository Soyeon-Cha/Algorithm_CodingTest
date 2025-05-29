#include <bits/stdc++.h>
using namespace std;

const int max_n = 1501;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int visited[max_n][max_n], visited_swan[max_n][max_n], r, c, day, y, x, swan_y, swan_x;
char a[max_n][max_n];
queue<pair<int, int>> water, water_temp, swan, swan_temp;

string s;

bool move_swan(){
    while(swan.size()){
        tie(y, x) = swan.front();
        swan.pop();
        
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited_swan[ny][nx]){
                continue;
            }

            visited_swan[ny][nx] = 1;
            
            if(a[ny][nx] == '.'){
                swan.push({ny, nx});
            }
            else if(a[ny][nx] == 'X'){
                swan_temp.push({ny, nx});
            }
            else if(a[ny][nx] == 'L'){
                return true;
            }
        }
    }
    return false;
}

void water_melt(){
    while(water.size()){
        tie(y, x) = water.front();
        water.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited_swan[ny][nx]){
                continue;
            }

            if(a[ny][nx] == 'X'){
                visited[ny][nx] = 1;
                water_temp.push({ny, nx});
                a[ny][nx] = '.';
            }
        }
    }
}

void queue_clear(queue<pair<int, int>> &q){
    queue<pair<int, int>> empty;
    swap(q, empty);
}

int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        cin >> s;
        for(int j=0; j<c; j++){
            a[i][j] = s[j];
            if(a[i][j] == 'L'){
                swan_y = i;
                swan_x = j;
            }
            if(a[i][j] == '.' || a[i][j] == 'L'){
                visited[i][j] = 1;
                water.push({i, j});
            }
        }
    }
    
    swan.push({swan_y, swan_x});
    visited_swan[swan_y][swan_x] = 1;
    
    while(true){
        // 백조들이 만난 경우
        if(move_swan()){
            break;
        }

        water_melt();

        water = water_temp;
        swan = swan_temp;
        queue_clear(water_temp);
        queue_clear(swan_temp);
        day++;
    }
    cout << day << '\n';
    return 0;
}
