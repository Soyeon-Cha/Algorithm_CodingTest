#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool check(string s){
    stack<char> st;
    for(char c : s){
        if(c == '('){
            st.push(c);
        }
        else{
            if(!st.empty()){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    cin >> n;
    while(n--){
        cin >> s;
        if(check(s)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
