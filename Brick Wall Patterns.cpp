#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> dp(51, 0);
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= 50; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    int num;
    while(cin >> num && num){
        cout << dp[num] << endl;
    }
}

// Fibonacci: N bricks pattern = (N-1 bricks pattern and one vertical brick) + (N-2 bricks pattern and two horizontal bricks)
// dp[N] = dp[N-1] + dp[N-2]