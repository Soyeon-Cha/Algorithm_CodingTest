#include <bits/stdc++.h>
using namespace std;

int n;
string s, fname, pre, suf;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 알파벳 소문자 여러 개, * 한 개
    // *은 문자열의 시작, 끝에 위치하지 않음

    cin >> n;
    cin >> s;

    int pos = s.find('*');
    pre = s.substr(0, pos);
    suf = s.substr(pos + 1);

    while(n--){
        cin >> fname;
        if(pre.size() + suf.size() > fname.size()){
            cout << "NE\n";
        }
        else{
            if(pre == fname.substr(0, pre.size()) && suf == fname.substr(fname.size() - suf.size())){
                cout << "DA\n";
            }
            else{
                cout << "NE\n";
            }
        }
    }
    return 0;
}
