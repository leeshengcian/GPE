#include <bits/stdc++.h>
using namespace std;

int Joseph(int N, int m){
    vector<int> pos(N+1);
    pos[1] = 1;
    for(int i = 2; i <= N; i++){
        pos[i] = (pos[i-1] + (m-1)) % i + 1;
    }
    return pos[N];
}

int main(){
    int N;
    while(cin >> N && N != 0){
        int m;
        if(N == 13){
            m = 1;
        }

        else{
            m = 2;
            while(Joseph(N - 1, m) != 12){
                m++;
            }
        }
        cout << m << endl;
    }
    return 0;
}

// 思路：在 N 人,間距 m 下最後消去的 index 為 13 -> J(N, m) = 13
// 需找到最小的 m 符合 J(N-1, m) = 12
// pos[i] 儲存 N = i 時最後消去的 index
// 利用固定的 m 從 pos[1] 推導至 pos[N]，直到該 m 使得 pos[N] == 12
