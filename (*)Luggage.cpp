#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;

    string dummy;
    getline(cin, dummy);

    while(num--){
        string line, tmp;
        vector<int> weight;
        getline(cin, line);
        stringstream ss(line);
        while(ss >> tmp){
            weight.push_back(stoi(tmp));
        }

        int sum = accumulate(weight.begin(), weight.end(), 0);
        if(sum % 2 == 1){
            cout << "NO" << endl;
            continue;
        }

        vector<int> dp(sum+1, 0);
        dp[0] = 1;

        for(int i = 0; i < weight.size(); i++){
            for(int j = sum; j >= weight[i]; j--){
                if(dp[j - weight[i]]){
                    dp[j] = 1;
                }
            }
        }

        if(dp[sum/2])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}