#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    while(cin >> num && num){
        set<int> S;
        S.insert(num);

        while(1){
            int tmp = num*num;
            tmp /= 100;
            tmp %= 10000;

            if(S.find(tmp) != S.end())
                break;
            else
                S.insert(tmp);
            
            num = tmp;
        }

        cout << S.size() << endl;
    }
}