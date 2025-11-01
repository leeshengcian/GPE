#include <bits/stdc++.h>
using namespace std;

int Compute_bit_sum(int N){
    int sum = 0;
    while(N){
        sum += N % 10;
        N /= 10;
    }
    return sum;
}

bool isSmith(int N){
    int BigNum = N;
    int bit_sum = Compute_bit_sum(N);
    int prime_bit_sum = 0;
    bool isPrime = true;

    for(int i = 2; i <= sqrt(N); i++){
        int time = 0;
        while(N % i == 0){
            time++;
            N /= i;
            isPrime = false;
        }
        prime_bit_sum += time * Compute_bit_sum(i);
    }

    if(isPrime)
        return false;
    
    if(!isPrime && N > 1){
        prime_bit_sum += Compute_bit_sum(N);
    }

    if(bit_sum == prime_bit_sum){
        cout << BigNum << endl;
        return true;
    }
    else 
        return false;
}

int main(){
    int case_num;
    cin >> case_num;
    while(case_num--){
        int number;
        cin >> number;
        for(int i = number+1; ;i++){
            if(isSmith(i))
                break;
        }
    }
}