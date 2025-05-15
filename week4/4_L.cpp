#include <bits/stdc++.h>
using namespace std;

int t, n, x;
string p, nums;

int main(){
    cin >> t;
    for(int i=0; i<t; i++){

        // 숫자 저장해두는 덱
        deque <int> d;

        cin >> p >> n >> nums;
        x = 0;

        for(char c : nums){
            // 수 입력받기
            // '[' 또는 ']'인 경우
            if(c=='[' || c==']'){
                continue;
            }

            // 숫자인 경우
            if(c>='0' && c<='9'){
                x = x*10 + c - '0';
            }
            
            // ','인 경우 현재 수를 덱에 넣기
            else{
                if(x > 0){
                    d.push_back(x);
                }
                x = 0;
            }
        }

        // 남아있는 수를 덱에 삽입
        if(x>0){
            d.push_back(x);
        }

        bool error = false, rev = false;

        // 명령 수행
        for(char a : p){

            // R인 경우
            if(a=='R'){
                rev = !rev;
            }

            // D인 경우
            else{
                if(d.empty()){
                    error = true;
                    break;
                }

                // 뒤집어진 경우
                if(rev){
                    d.pop_back();
                }

                // 뒤집어지지 않은 경우
                else{
                    d.pop_front();
                }
            }
        }

        // error가 발생한 경우
        if(error){
            cout << "error" << '\n';
        }

        // error가 발생하지 않은 경우
        else{
            cout << "[";

            // 뒤집어진 경우 실제로 뒤집기
            if(rev){
                reverse(d.begin(), d.end());
            }

            for(int i=0; i<d.size(); i++){
                cout << d[i];
                if(i<d.size()-1){
                    cout << ",";
                }
            }
            cout << "]\n";
        }
    }
}
