#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // A 65~90, a 97~122

    getline(cin, s);
    for(int i=0; i<s.size(); i++){
        if(65<=s[i] && s[i]<=90){
            if(s[i] + 13 > 90){
                s[i] = s[i] + 13 - 26;
            }
            else{
                s[i] += 13;
            }
        }
        else if(97<=s[i] && s[i]<=122){
            if(s[i] + 13 > 122){
                s[i] = s[i] + 13 - 26;
            }
            else{
                s[i] += 13;
            }
        }
        cout << s[i];
    }
    return 0;
}
