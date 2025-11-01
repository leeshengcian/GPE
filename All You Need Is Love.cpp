#include <bits/stdc++.h>
using namespace std;

int BinaryToInt(const string& num_string){
    int result = 0;
    for(char c : num_string){
        result = result * 2 + (c - '0');
    }
    return result;
}

int main(){
    int pair_num;
    while(cin >> pair_num){
        for(int i = 1; i <= pair_num; i++){
            string s1, s2;
            cin >> s1 >> s2;

            int num1 = BinaryToInt(s1);
            int num2 = BinaryToInt(s2);

            int gcd = __gcd(num1, num2);
            
            if(gcd > 1){
                cout << "Pair #" << i << ": All you need is love!" << endl;
            }
            else
                cout << "Pair #" << i << ": Love is not all you need!" << endl;
        }
    }
}