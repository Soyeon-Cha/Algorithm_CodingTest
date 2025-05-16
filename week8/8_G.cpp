#include <bits/stdc++.h>
using namespace std;

int t, n;
string dp[1001];
map<char, char> mp;
char a[6] = {'(', ')', '{', '}', '[', ']'};

// dp의 값을 갱신할지 말지 결정
bool check(string before, string after){
    // 갱신하려는 값이 비어있는 경우
    if(before == "" && after == ""){
        return false;
    }

    // 갱신 전의 값이 비어있는 경우
    if(before == ""){
        return true;
    }

    // 갱신하려는 값의 자릿수가 갱신 전의 값의 자릿수가가 같은 경우 사전순 비교
    if(before.size() == after.size()){
        return after < before;
    }

    // 갱신 전 값과 갱신하려는 값의 자릿수가 다른 경우
    return after.size() < before.size();
}

int main(){
    // 아스키코드를 이용해서 괄호와 숫자 매핑
    for(int i=0; i<6; i++){
        mp[i + '1'] = a[i];
    }

    dp[1] = "12";
    dp[2] = "34";
    dp[3] = "56";

    for(int i=1; i<=1000; i++){
        if(i%2 == 0 && check(dp[i], '1' + dp[i/2] + '2')){
            dp[i] = '1' + dp[i/2] + '2';
        }
        if(i%3 == 0 && check(dp[i], '3' + dp[i/3] + '4')){
            dp[i] = '3' + dp[i/3] + '4';
        }
        if(i%5 == 0 && check(dp[i], '5' + dp[i/5] + '6')){
            dp[i] = '5' + dp[i/5] + '6';
        }

        for(int j=1; j<=i; j++){
            if(check(dp[i], dp[j] + dp[i-j])){
                dp[i] = dp[j] + dp[i-j];
            }
        }
    }

    cin >> t;

    while(t--){
        cin >> n;
        for(char a : dp[n]){
            cout << mp[a];
        }
        cout << "\n";
    }
}
