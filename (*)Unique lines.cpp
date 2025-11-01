#include <bits/stdc++.h>
using namespace std;

static long long GCD3(long long a, long long b, long long c){
    a = llabs(a);
    b = llabs(b);
    c = llabs(c);

    long long g = gcd(a, b);
    g = gcd(g, c);

    return g == 0 ? 1 : g;
}

int main(){
    int case_num;
    cin >> case_num;

    while(case_num--){
        int N;
        cin >> N;
        vector<long long> x(N), y(N);

        for(int i = 0; i < N; i++){
            cin >> x[i] >> y[i];
        }

        set<tuple<long long, long long, long long>> S;

        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                long long dx = x[j] - x[i];
                long long dy = y[j] - y[i];

                long long A = dy;
                long long B  = -dx;
                long long C = dx * y[i] - dy * x[i];

                long long g = GCD3(A,B,C);
                A /= g;
                B /= g;
                C /= g;

                if(A < 0 || (A == 0 && B < 0)){
                    A = -A; B = -B; C = -C;
                }

                S.emplace(A,B,C);
            }
        }

        cout << S.size() << endl;
    }
    return 0;
}


// 思路：每條 unique line 會對應到一個直線方程式：Ax + By + C = 0
// 使用窮舉法找出兩點對應的 (A, B, C), 利用 set 存放 unique (A, B, C) -> S.emplace()
// A = dy, B = -dx, C = dx * y1 - dy * x1
// 避免 k(A, B, C) 也被存放進去，找出三數的 gcd 並作約分