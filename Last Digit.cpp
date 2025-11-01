#include <bits/stdc++.h>
using namespace std;

int last[20] = {0,1,5,2,8,3,9,2,8,7,7,8,4,7,3,8,4,1,5,4};

int main(){
    string number;
    while(cin >> number){
        int L = number.length();
        if(L == 1 && number[L-1] == '0')
            break;
        int a = number[L-1] - '0';
        if(L > 1)
            a += (number[L-2] - '0') * 10;

        cout << (last[a%20] + (a/20*4)) % 10 << endl;
    }
}