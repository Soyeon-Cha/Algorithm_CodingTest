#include <bits/stdc++.h>
using namespace std;

// 세로 h, 가로 w, i행 j열 (i, j)
// 구름 동쪽 1km/1분

int h, w;

int main(){
    cin >> h >> w;
    for(int i=0; i<h; i++){
        string str;
        cin >> str;
        int cloud = -1;
        for(int j=0; j<w; j++){
            // 처음부터 c인 경우
            if(str[j] == 'c'){
                cloud = 0;
            }

            // .인 경우
            else if(str[j] == '.'){
                // 구름이 지나가는 경우
                if(cloud != -1){
                    cloud++;
                }

                // 구름이 지나가지 않는 경우
            }
            cout << cloud << " ";
        }
        cout << '\n';
    }
}
