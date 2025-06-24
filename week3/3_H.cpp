#include <bits/stdc++.h>
using namespace std;

#define prev aaa

int n, k, visited[200004], prev[200004], ret, here, cnt, next;
vector<int> v;
queue<int> q;

int main(){
    cin >> n >> k;

    visited[n] = 1;
    q.push(n);

    while(q.size()){
        here = q.front();
        q.pop();

        if(here == k){
            ret = visited[k];
            break;
        }

        for(int next : {here + 1, here - 1, here * 2}){
            if(next >= 200004 || next < 0 || visited[next]){
                continue;
            }

            visited[next] = visited[here] + 1;
            prev[next] = here;
            q.push(next);
        }
    }

    for(int i=k; i!=n; i=prev[i]){
        v.push_back(i);
    }

    v.push_back(n);
    cout << ret - 1 << "\n";
    reverse(v.begin(), v.end());

    for(int i : v){
        cout << i << " ";
    }

    return 0;
}
