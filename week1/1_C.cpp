#include <bits/stdc++.h>
using namespace std;

int a, b, c, x, y, cnt[105], ans;

int main(){
    cin >> a >> b >> c;

    for (int i=0; i<3; i++){
        cin >> x >> y;
        for (int j=x; j<y; j++){
            cnt[j]++;
        }
    }

    for (int j=1; j<100; j++){
        if (cnt[j]){
            if (cnt[j]==1){
                ans += a;
            }
            else if (cnt[j]==2){
                ans += b*2;
            }
            else if (cnt[j]==3){
                ans += c*3;
            }
        }
    }
    cout << ans;
    return 0;
}
