#include <bits/stdc++.h>
#define MAXN 100020
using namespace std;

int b[MAXN];

void kmp_process(const string& str){
    int i = 0, j = -1;
    int N = str.length();
    b[0] = -1;
    while(i < N){
        while(j >= 0 && str[i] != str[j]){
            j = b[j];
        }
        i++;
        j++;
        b[i] = j;
    }
}

int kmp(const string& strA, const string& strB){
    int i = 0, j = 0;
    int N = strA.length();

    while(i < N){
        while(j >= 0 && strA[i] != strB[j]){
            j = b[j];
        }
        i++;
        j++;
    }
    return j;
}
int main(){
    string strA;
    while(cin >> strA){
        string strB = strA;
        reverse(strB.begin(), strB.end());
        kmp_process(strB);
        int n = kmp(strA, strB);
        cout << strA << strB.substr(n) << endl;
    }
    return 0;
}