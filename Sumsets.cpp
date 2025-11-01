#include <bits/stdc++.h>
using namespace std;

long long find(const vector<long long>& nums){
    for(int d = nums.size() - 1; d > 2; d--){
        for(int a = 0; a < nums.size() - 3; a++){
            for(int b = a+1; b < nums.size() - 2; b++){
                for(int c = b+1; c < nums.size() - 1; c++){
                    if(nums[a] + nums[b] + nums[c] == nums[d] && a!=b && b!=c && c!=d)
                        return nums[d];
                }
            }
        }
    }
    return LLONG_MAX;
}

int main(){
    int N;
    while(cin >> N && N != 0){
        vector<long long> nums(N);
        for(int i = 0; i < N; i++){
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        long long res = find(nums);

        if(res == LLONG_MAX){
            cout << "no solution" << endl;
        }
        else
            cout << res << endl;
    }

    return 0;
}

// 思路：先將數列排序，a,b,c 從頭遍尋，d 從最尾端找回來，注意邊界