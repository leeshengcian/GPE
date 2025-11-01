#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    while(cin >> num){
        vector<int> nums(num);
        for(int i = 0; i < num; i++){
            cin >> nums[i];
        }

        vector<int> dp(num, 1);
        int res = 0;

        for(int i = 0; i < num; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        cout << res << endl;
    }
}