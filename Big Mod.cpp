#include <bits/stdc++.h>
using namespace std;

long long bigmod(long long B, long long P, long long M){
    if(P == 0){
        return 1;
    }
    else if(P == 1){
        return B % M;
    }
    else{
        long long res = bigmod(B, P/2, M);

        if(P%2){
            return (res * res * B) % M;
        }
        else{
            return (res * res) % M;
        }
    }
}

int main(){
    long long b, p, m;
    while(cin >> b >> p >> m){
        cout << bigmod(b, p, m) << endl;
    }
    return 0;
}