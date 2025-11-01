#include <bits/stdc++.h>
using namespace std;

bool compare(const string& a, const string& b){
    return a+b > b+a;
}

int main(){
    int num;
    while(cin >> num && num){
        vector<string> strs(num);
        for(int i = 0; i < num; i++){
            cin >> strs[i];
        }

        sort(strs.begin(), strs.end(), compare);

        string res = "";
        for(auto s : strs){
            res += s;
        }
        cout << res << endl;
    }
}