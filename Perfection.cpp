#include <bits/stdc++.h>
using namespace std;

void factor(int N, vector<int> &fac){
    for(int i = 1; i < N; i++){
        if(N % i == 0){
            fac.push_back(i);
        }
    }
}

int main(){
    int num;
    cout << "PERFECTION OUTPUT" << endl;
    while(cin >> num && num){
        vector<int> factor_list;
        factor(num, factor_list);

        int sum = accumulate(factor_list.begin(), factor_list.end(), 0);
        if(sum == num){
            cout << right << setw(5) << num << "  PERFECT" << endl;
        }
        else if(sum < num){
            cout << right << setw(5) << num << "  DEFICIENT" << endl;
        }
        else{
            cout << right << setw(5) << num << "  ABUNDANT" << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
}