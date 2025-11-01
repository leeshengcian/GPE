#include <bits/stdc++.h>
using namespace std;

bool isHappy(int num){
    set<int> S;
    while(num != 1){
        S.insert(num);
        int sum = 0;
        while(num){
            int last = num % 10;
            sum += last * last;
            num /= 10;
        }
        num = sum;
        if(S.find(sum) != S.end())
            return false;
    }
    return true;
}

int main(){
    int N;
    cin >> N;
    int count = 0;
    while(N--){
        count++;
        int num;
        cin >> num;
        bool b = isHappy(num);
        if(b)
            cout << "Case #" << count << ": " << num << " is a Happy number." << endl;
        else
            cout << "Case #" << count << ": " << num << " is an Unhappy number." << endl;
    }
}