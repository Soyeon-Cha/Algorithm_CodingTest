#include <bits/stdc++.h>
using namespace std;

int n, m, j, k, l, r, ret;

int main(){
    cin >> n >> m;
    cin >> j;

    l = 1;

    for(int i=0; i<j; i++){
        cin >> k;
        r = l + m - 1;

        if(k >= l && k <= r){
            continue;
        }
        else{
            if(k<l){
                ret += (l-k);
                l = k;
            }
            else{
                l += (k-r);
                ret += (k-r);
            }
        }
    }
    cout << ret << '\n';
    return 0;
}
