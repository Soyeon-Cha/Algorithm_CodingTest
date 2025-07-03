#include <bits/stdc++.h>
using namespace std;

int n, arr[26];
string str, ret;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        arr[str[0]-'a']++;
    }

    for(int i=0; i<26; i++){
        if(arr[i] >= 5){
            ret += i + 'a';
        }
    }

    if(ret.size()){
        cout << ret << "\n";
    }
    else{
        cout << "PREDAJA" << "\n";
    }
}
