#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(cin >> N && N){
        int root = sqrt(N);

        if(root * root == N){
            cout << "yes" << endl;
        }
        else
            cout << "no" << endl;
    }
    return 0;
}