#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        
        int two = 0, five = 0;
        
        for(int j=2; j<=n; j*=2){
            two += n / j;
        }

        for(int j=5; j<=n; j*=5){
            five += n / j;
        }

        cout << min(two, five) << "\n";
    }
    return 0;
}
