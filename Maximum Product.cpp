#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    int case_num = 0;
    while(cin >> num){
        case_num++;
        vector<int> S(num);
        for(int i = 0; i < num; i++){
            cin >> S[i];
        }

        long long ans = 0;
        for(int i = 0; i < num; i++){
            long long tmp = 1;
            for(int j = i; j < num; j++){
                tmp *= S[j];
                ans = max(ans, tmp);
            }
        }

        cout << "Case #" << case_num << ": The maximum product is " << ans << "." << endl;
    }
}