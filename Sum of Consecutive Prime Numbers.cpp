#include <bits/stdc++.h>
using namespace std;

int N = 10001;

int main(){
    int visit[N] = {0};
    vector<int> primes;
    for(int i = 2; i <= N; i++){
        if(!visit[i]){
            for(int j = i*i; j <= N; j += i){
                visit[j] = 1;
            }
            primes.push_back(i);
        }
    }

    int num;
    while(cin >> num && num){
        int count = 0;
        for(int i = 0; i < primes.size(); i++){
            int sum = 0;
            for(int j = i; j < primes.size(); j++){
                sum += primes[j];
                if(sum == num){
                    count++;
                    break;
                }
            }
        }

        cout << count << endl;
    }
}