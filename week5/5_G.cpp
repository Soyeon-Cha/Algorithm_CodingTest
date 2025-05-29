#include <bits/stdc++.h>
using namespace std;

// 연속된 한 개 이상의 소수의 합
// 한 소수는 덧셈에 한 번만 사용 가능

int n, pn[2000001], p=0, lo, hi, ans, sum;
bool a[4000001];


int main(){ 
    cin >> n;
    for(int i=2; i<=n; i++){
        if(a[i]){
            continue;
        }
        for(int j=2*i; j<=n; j+=i){
            a[j] = 1;
        }
    }

    for(int i=2; i<=n; i++){
        if(!a[i]){
            pn[p] = i;
            p++;
        }
    }
    
    while(true){
        if(sum >= n){
            sum -= pn[lo];
            lo++;
        }
        else if(hi == p){
            break;
        }
        else{
            sum += pn[hi];
            hi++;
        }

        if(sum == n){
            ans++;
        }
    }
    cout << ans;
}
