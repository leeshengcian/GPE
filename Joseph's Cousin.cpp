#include <bits/stdc++.h>
using namespace std;

int visit[35005] = {0};
int primes[4000];

int main(){
    int primes_index = 0;
    for(int i = 2; i < 35005; i++){
        if(!visit[i]){
            primes[primes_index++] = i;
            for(int j = i * i; j < 35005; j += i){
                visit[j] = 1;
            }
        }
    }

    int num;
    while(cin >> num && num){
        int ans = 0;
        for(int i = 2; i <= num; i++){ // primes[n-2] ~ primes[0]: total n-1 primes
            ans = (ans + primes[num-i]) % i;
        }
        cout << ans+1 << endl; //
    }
    return 0;
}