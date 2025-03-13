#include <bits/stdc++.h>
using namespace std;

string str, temp;
int ans = 0;

int main(){
    cin >> str;
    temp = str;
    reverse(temp.begin(), temp.end());
    if (str == temp){
        ans = 1;
    }
    cout << ans;
    return 0;
}
